#ifndef CARGO_H
#define CARGO_H
#include "component.h"

class cargo: public component{
private:
    int cargoCapacity;
public:
    cargo(char, double, double, int, int);
    int getCargoCapacity();
    virtual ~cargo();
    virtual double calculateEfficiency();
};

#endif