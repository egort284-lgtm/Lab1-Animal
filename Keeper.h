#ifndef KEEPER_H
#define KEEPER_H
#include <string>
#include "Animal.h"
class Keeper {
private:
    Animal** animals_;
    int size_;
    int capacity_;
    void grow();
    void clear();
public:
    Keeper();
    Keeper(const Keeper& other);
    Keeper& operator=(const Keeper& other);
    ~Keeper();
    int getSize() const;
    void add(Animal* animal);
    void remove(int index);
    void showAll() const;
    void edit(int index);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};
#endif
