#ifndef BIRD_H
#define BIRD_H
#include "Animal.h"
class Bird final : public Animal {
private:
    std::string food_;
    std::string habitat_;
public:
    Bird();
    Bird(const std::string& breed, const std::string& color, const std::string& food, const std::string& habitat);
    Bird(const Bird& other);
    ~Bird() override;
    std::string getFood() const;
    std::string getHabitat() const;
    void setFood(const std::string& food);
    void setHabitat(const std::string& habitat);
    std::string getType() const override;
    void input() override;
    void display() const override;
    void edit() override;
    Bird* clone() const override;
    void save(std::ostream& out) const override;
};
#endif
