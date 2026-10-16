#ifndef FISH_H
#define FISH_H
#include "Animal.h"
class Fish final : public Animal {
private:
    std::string foodType_;
public:
    Fish();
    Fish(const std::string& breed, const std::string& color, const std::string& foodType);
    Fish(const Fish& other);
    ~Fish() override;
    std::string getFoodType() const;
    void setFoodType(const std::string& foodType);
    std::string getType() const override;
    void input() override;
    void display() const override;
    void edit() override;
    Fish* clone() const override;
    void save(std::ostream& out) const override;
};
#endif
