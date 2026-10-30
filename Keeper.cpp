#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <utility>

Keeper::Keeper():animals_(nullptr),size_(0),capacity_(0){std::cout<<"[Keeper] vyzvan konstruktor bez parametrov\n";}
Keeper::Keeper(const Keeper& o):animals_(nullptr),size_(0),capacity_(0){
    std::cout<<"[Keeper] vyzvan konstruktor kopirovaniya\n";
    try{
        for(int i=0;i<o.size_;++i){
            Animal* copy=o.animals_[i]->clone();
            try{
                add(copy);
            }catch(...){
                delete copy;
                throw;
            }
        }
    }catch(...){
        clear();
        throw;
    }
}
Keeper& Keeper::operator=(const Keeper& o){
    if(this!=&o){
        Keeper temp(o);
        std::swap(animals_,temp.animals_);
        std::swap(size_,temp.size_);
        std::swap(capacity_,temp.capacity_);
    }
    std::cout<<"[Keeper] vyzvan operator prisvaivaniya\n";
    return *this;
}
Keeper::~Keeper(){std::cout<<"[Keeper] vyzvan destruktor\n";clear();}
void Keeper::clear(){for(int i=0;i<size_;++i)delete animals_[i];delete[] animals_;animals_=nullptr;size_=0;capacity_=0;}
void Keeper::grow(){
    int newCap=capacity_==0?4:capacity_*2;
    Animal** temp=new Animal*[newCap];
    for(int i=0;i<size_;++i)temp[i]=animals_[i];
    delete[] animals_;animals_=temp;capacity_=newCap;
}
int Keeper::getSize() const{return size_;}
void Keeper::add(Animal* a){
    if(!a)throw std::invalid_argument("Nelzya dobavit pustoy ukazatel na zhivotnoe.");
    if(size_==capacity_)grow();
    animals_[size_++]=a;
    std::cout<<"Obyekt dobavlen v Keeper.\n";
}
void Keeper::remove(int index){
    if(index<0||index>=size_)throw std::out_of_range("Net zhivotnogo s takim nomerom.");
    delete animals_[index];
    for(int i=index;i<size_-1;++i)animals_[i]=animals_[i+1];
    --size_;std::cout<<"Obyekt udalen.\n";
}
void Keeper::showAll() const{
    if(size_==0){std::cout<<"Khranilishche pusto.\n";return;}
    for(int i=0;i<size_;++i){std::cout<<"\n--- Zhivotnoe #"<<i+1<<" ---\n";animals_[i]->display();}
}
void Keeper::edit(int index){
    if(index<0||index>=size_)throw std::out_of_range("Net zhivotnogo s takim nomerom.");
    animals_[index]->edit();
}
void Keeper::saveToFile(const std::string& filename) const{
    std::ofstream out(filename);
    if(!out)throw std::runtime_error("Ne udalos otkryt fayl dlya sokhraneniya.");
    out<<size_<<'\n';
    for(int i=0;i<size_;++i)animals_[i]->save(out);
    if(!out)throw std::runtime_error("Oshibka pri zapisi dannyh v fayl.");
    std::cout<<"Dannye sokhraneny v fayl "<<filename<<".\n";
}
void Keeper::loadFromFile(const std::string& filename){
    std::ifstream in(filename);
    if(!in)throw std::runtime_error("Ne udalos otkryt fayl dlya chteniya.");
    int count;
    if(!(in>>count)||count<0||count>100000)throw std::runtime_error("Nekorrektnyy format fayla: nevernoe chislo obyektov.");
    Keeper temp;
    for(int i=0;i<count;++i){
        std::string type,b,c,x,y;
        if(!(in>>type))throw std::runtime_error("Fayl neozhidanno zakonchilsya.");
        in>>std::quoted(b)>>std::quoted(c);
        if(!in)throw std::runtime_error("Ne udalos prochitat obshchie dannye zhivotnogo.");
        if(type=="FISH"){
            if(!(in>>std::quoted(x)))throw std::runtime_error("Ne udalos prochitat tip pitaniya ryby.");
            temp.add(new Fish(b,c,x));
        }else if(type=="BIRD"){
            if(!(in>>std::quoted(x)>>std::quoted(y)))throw std::runtime_error("Ne udalos prochitat dannye ptitsy.");
            temp.add(new Bird(b,c,x,y));
        }else if(type=="CAT"){
            if(!(in>>std::quoted(x)>>std::quoted(y)))throw std::runtime_error("Ne udalos prochitat dannye koshki.");
            temp.add(new Cat(b,c,x,y));
        }else throw std::runtime_error("Neizvestnyy tip zhivotnogo v fayle: "+type);
    }
    *this=temp;
    std::cout<<"Dannye vosstanovleny iz fayla "<<filename<<".\n";
}
