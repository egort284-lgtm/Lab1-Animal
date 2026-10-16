#include "Cat.h"
#include <stdexcept>
#include <iomanip>
Cat::Cat():Animal(),owner_("ne ukazan"),name_("bez klichki"){std::cout<<"[Cat] vyzvan konstruktor bez parametrov\n";}
Cat::Cat(const std::string& b,const std::string& c,const std::string& o,const std::string& n):Animal(b,c),owner_(o),name_(n){std::cout<<"[Cat] vyzvan konstruktor s parametrami\n";}
Cat::Cat(const Cat& o):Animal(o),owner_(o.owner_),name_(o.name_){std::cout<<"[Cat] vyzvan konstruktor kopirovaniya\n";}
Cat::~Cat(){std::cout<<"[Cat] vyzvan destruktor\n";}
std::string Cat::getOwner() const{return owner_;} std::string Cat::getName() const{return name_;}
void Cat::setOwner(const std::string& v){if(v.empty())throw std::invalid_argument("FIO vladeltsa ne mozhet byt pustym.");owner_=v;}
void Cat::setName(const std::string& v){if(v.empty())throw std::invalid_argument("Klichka ne mozhet byt pustoy.");name_=v;}
std::string Cat::getType() const{return "Koshka";}
void Cat::input(){Animal::input();std::string v;std::cout<<"FIO vladeltsa: ";std::getline(std::cin,v);setOwner(v);std::cout<<"Klichka: ";std::getline(std::cin,v);setName(v);}
void Cat::display() const{Animal::display();std::cout<<"FIO vladeltsa: "<<owner_<<"\nKlichka: "<<name_<<"\n";}
void Cat::edit(){Animal::edit();std::string v;std::cout<<"Novyy vladelets (pusto - bez izmeneniy): ";std::getline(std::cin>>std::ws,v);if(!v.empty())setOwner(v);std::cout<<"Novaya klichka (pusto - bez izmeneniy): ";std::getline(std::cin,v);if(!v.empty())setName(v);}
Cat* Cat::clone() const{return new Cat(*this);}
void Cat::save(std::ostream& out) const{out<<"CAT\n"<<std::quoted(breed_)<<'\n'<<std::quoted(color_)<<'\n'<<std::quoted(owner_)<<'\n'<<std::quoted(name_)<<'\n';}
