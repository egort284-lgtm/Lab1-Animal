#include "Bird.h"
#include <stdexcept>
#include <iomanip>
Bird::Bird():Animal(),food_("ne ukazano"),habitat_("ne ukazano"){std::cout<<"[Bird] vyzvan konstruktor bez parametrov\n";}
Bird::Bird(const std::string& b,const std::string& c,const std::string& f,const std::string& h):Animal(b,c),food_(f),habitat_(h){std::cout<<"[Bird] vyzvan konstruktor s parametrami\n";}
Bird::Bird(const Bird& o):Animal(o),food_(o.food_),habitat_(o.habitat_){std::cout<<"[Bird] vyzvan konstruktor kopirovaniya\n";}
Bird::~Bird(){std::cout<<"[Bird] vyzvan destruktor\n";}
std::string Bird::getFood() const{return food_;} std::string Bird::getHabitat() const{return habitat_;}
void Bird::setFood(const std::string& v){if(v.empty())throw std::invalid_argument("Ratsion ptitsy ne mozhet byt pustym.");food_=v;}
void Bird::setHabitat(const std::string& v){if(v.empty())throw std::invalid_argument("Sreda obitaniya ne mozhet byt pustoy.");habitat_=v;}
std::string Bird::getType() const{return "Ptitsa";}
void Bird::input(){Animal::input();std::string v;std::cout<<"Chem pitaetsya: ";std::getline(std::cin,v);setFood(v);std::cout<<"Gde obitaet: ";std::getline(std::cin,v);setHabitat(v);}
void Bird::display() const{Animal::display();std::cout<<"Pitanie: "<<food_<<"\nSreda obitaniya: "<<habitat_<<"\n";}
void Bird::edit(){Animal::edit();std::string v;std::cout<<"Novyy ratsion (pusto - bez izmeneniy): ";std::getline(std::cin>>std::ws,v);if(!v.empty())setFood(v);std::cout<<"Novaya sreda obitaniya (pusto - bez izmeneniy): ";std::getline(std::cin,v);if(!v.empty())setHabitat(v);}
Bird* Bird::clone() const{return new Bird(*this);}
void Bird::save(std::ostream& out) const{out<<"BIRD\n"<<std::quoted(breed_)<<'\n'<<std::quoted(color_)<<'\n'<<std::quoted(food_)<<'\n'<<std::quoted(habitat_)<<'\n';}
