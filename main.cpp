#include "Keeper.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

int readInt(const std::string& prompt){
    int value;
    while(true){
        std::cout<<prompt;
        if(std::cin>>value){std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');return value;}
        std::cout<<"Oshibka: nuzhno vvesti tseloe chislo.\n";
        std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}
Animal* createAnimal(){
    std::cout<<"Tip zhivotnogo: 1 - ryba, 2 - ptitsa, 3 - koshka\n";
    int type=readInt("Vash vybor: ");
    Animal* animal=nullptr;
    switch(type){
        case 1: animal=new Fish(); break;
        case 2: animal=new Bird(); break;
        case 3: animal=new Cat(); break;
        default: throw std::invalid_argument("Neizvestnyy tip zhivotnogo.");
    }
    try{animal->input();}
    catch(...){delete animal;throw;}
    return animal;
}
int main(){
    Keeper keeper;
    bool running=true;
    while(running){
        std::cout<<"\n========== MENU ==========\n"
                 <<"1. Dobavit zhivotnoe\n"
                 <<"2. Udalit zhivotnoe\n"
                 <<"3. Pokazat vse obyekty\n"
                 <<"4. Izmenit zhivotnoe\n"
                 <<"5. Sokhranit v fayl\n"
                 <<"6. Vosstanovit iz fayla\n"
                 <<"7. Pokazat kolichestvo zhivotnyh\n"
                 <<"0. Vyhod\n";
        int choice=readInt("Vyberite deystvie: ");
        try{
            switch(choice){
                case 1: keeper.add(createAnimal()); break;
                case 2: keeper.remove(readInt("Nomer zhivotnogo dlya udaleniya: ")-1); break;
                case 3: keeper.showAll(); break;
                case 4: keeper.edit(readInt("Nomer zhivotnogo dlya izmeneniya: ")-1); break;
                case 5:{
                    std::string f;std::cout<<"Imya fayla (naprimer animals.txt): ";std::getline(std::cin,f);
                    if(f.empty())throw std::invalid_argument("Imya fayla ne mozhet byt pustym.");
                    keeper.saveToFile(f);break;
                }
                case 6:{
                    std::string f;std::cout<<"Imya fayla (naprimer animals.txt): ";std::getline(std::cin,f);
                    if(f.empty())throw std::invalid_argument("Imya fayla ne mozhet byt pustym.");
                    keeper.loadFromFile(f);break;
                }
                case 7: std::cout<<"Kolichestvo zhivotnyh: "<<keeper.getSize()<<'\n';break;
                case 0: running=false;break;
                default: std::cout<<"Net takogo punkta menu.\n";
            }
        }catch(const std::exception& e){std::cout<<"Oshibka: "<<e.what()<<'\n';}
    }
    std::cout<<"Zavershenie programmy.\n";
    return 0;
}
