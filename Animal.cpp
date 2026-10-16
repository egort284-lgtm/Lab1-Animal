#include "Animal.h"
#include <stdexcept>
#include <limits>

Animal::Animal() : breed_("ne ukazana"), color_("ne ukazan") {
    std::cout << "[Animal] vyzvan konstruktor bez parametrov\n";
}
Animal::Animal(const std::string& breed, const std::string& color) : breed_(breed), color_(color) {
    std::cout << "[Animal] vyzvan konstruktor s parametrami\n";
}
Animal::Animal(const Animal& other) : breed_(other.breed_), color_(other.color_) {
    std::cout << "[Animal] vyzvan konstruktor kopirovaniya\n";
}
Animal::~Animal() { std::cout << "[Animal] vyzvan destruktor\n"; }

std::string Animal::getBreed() const { return breed_; }
std::string Animal::getColor() const { return color_; }
void Animal::setBreed(const std::string& breed) {
    if (breed.empty()) throw std::invalid_argument("Poroda ne mozhet byt pustoy.");
    breed_ = breed;
}
void Animal::setColor(const std::string& color) {
    if (color.empty()) throw std::invalid_argument("Okraska ne mozhet byt pustoy.");
    color_ = color;
}
void Animal::input() {
    std::string value;
    std::cout << "Vvedite porodu: "; std::getline(std::cin >> std::ws, value); setBreed(value);
    std::cout << "Vvedite okras: "; std::getline(std::cin, value); setColor(value);
}
void Animal::display() const {
    std::cout << "Tip: " << getType() << "\nPoroda: " << breed_ << "\nOkras: " << color_ << '\n';
}
void Animal::edit() {
    std::string value;
    std::cout << "Novaya poroda (pusto - bez izmeneniy): ";
    std::getline(std::cin >> std::ws, value);
    if (!value.empty()) setBreed(value);
    std::cout << "Novyy okras (pusto - bez izmeneniy): ";
    std::getline(std::cin, value);
    if (!value.empty()) setColor(value);
}
std::ostream& operator<<(std::ostream& out, const Animal& animal) {
    out << "Tip: " << animal.getType() << ", порода: " << animal.breed_ << ", окрас: " << animal.color_;
    return out;
}
