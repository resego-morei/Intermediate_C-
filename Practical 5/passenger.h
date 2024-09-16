#ifndef PASSENGER_H
#define PASSENGER_H
#include "component.h"

class passenger: public component{
private:
    int passengerCapacity;
public:
    passenger(char, double, double, int, int);
    int getPassengerCapacity();

    virtual ~passenger();
    virtual double calculateEfficiency();
};

#endif