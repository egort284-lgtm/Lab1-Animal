#include "Fish.h"
#include <stdexcept>
#include <iomanip>
Fish::Fish() : Animal(), foodType_("ne ukazan") { std::cout << "[Fish] vyzvan konstruktor bez parametrov\n"; }
Fish::Fish(const std::string& b,const std::string& c,const std::string& f):Animal(b,c),foodType_(f){std::cout<<"[Fish] vyzvan konstruktor s parametrami\n";}
Fish::Fish(const Fish& o):Animal(o),foodType_(o.foodType_){std::cout<<"[Fish] vyzvan konstruktor kopirovaniya\n";}
Fish::~Fish(){std::cout<<"[Fish] vyzvan destruktor\n";}
std::string Fish::getFoodType() const{return foodType_;}
void Fish::setFoodType(const std::string& v){if(v.empty())throw std::invalid_argument("Tip pitaniya ryby ne mozhet byt pustym.");foodType_=v;}
std::string Fish::getType() const{return "Ryba";}
void Fish::input(){Animal::input();std::string v;std::cout<<"Vvedite tip pitaniya: ";std::getline(std::cin,v);setFoodType(v);}
void Fish::display() const{Animal::display();std::cout<<"Tip pitaniya: "<<foodType_<<"\n";}
void Fish::edit(){Animal::edit();std::string v;std::cout<<"Novyy tip pitaniya (pusto - bez izmeneniy): ";std::getline(std::cin>>std::ws,v);if(!v.empty())setFoodType(v);}
Fish* Fish::clone() const{return new Fish(*this);}
void Fish::save(std::ostream& out) const{out<<"FISH\n"<<std::quoted(breed_)<<'\n'<<std::quoted(color_)<<'\n'<<std::quoted(foodType_)<<'\n';}
