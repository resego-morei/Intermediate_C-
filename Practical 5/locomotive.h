#ifndef LOCOMOTIVE_H
#define LOCOMOTIVE_H
#include "component.h"

class locomotive: public component{
private:
    int powerGen;
public:
    locomotive(char, double, double, int, int);
    int getPowerGen();

    virtual ~locomotive();
    virtual double calculateEfficiency();
};

#endif