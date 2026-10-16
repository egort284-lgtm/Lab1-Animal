#ifndef CAT_H
#define CAT_H
#include "Animal.h"
class Cat final : public Animal {
private:
    std::string owner_;
    std::string name_;
public:
    Cat();
    Cat(const std::string& breed, const std::string& color, const std::string& owner, const std::string& name);
    Cat(const Cat& other);
    ~Cat() override;
    std::string getOwner() const;
    std::string getName() const;
    void setOwner(const std::string& owner);
    void setName(const std::string& name);
    std::string getType() const override;
    void input() override;
    void display() const override;
    void edit() override;
    Cat* clone() const override;
    void save(std::ostream& out) const override;
};
#endif
