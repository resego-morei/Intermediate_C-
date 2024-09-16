#include <cmath>
#include <iostream>
#include "component.h"
#include "passenger.h"

using namespace std;

passenger :: passenger(char type, double weight, double cost, int powerDrain, int passengerCapacity) : component(type,weight,cost,powerDrain){
    this->passengerCapacity = passengerCapacity;
}

int passenger :: getPassengerCapacity(){
    return passengerCapacity;
}

passenger :: ~passenger(){}

double passenger :: calculateEfficiency(){
    return (((this->getWeight() * this->passengerCapacity)/ this->getPowerDrain())/ this->getCost());
}