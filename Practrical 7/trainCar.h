#ifndef trainCar_h
#define trainCar_h

#include <iostream>
#include <string>
#include <cstdlib>


class trainCar{
private:
    int cost;

public:
    trainCar(int);
    ~trainCar();
    int getCost();
    trainCar* next;
};

#endif