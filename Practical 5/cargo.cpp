#include "component.h"
#include "cargo.h"
#include <cmath>
#include "iostream"

using namespace std;

cargo :: cargo(char type, double weight, double cost, int powerDrain, int cargoCapacity) : component(type,weight,cost,powerDrain){
    this->cargoCapacity = cargoCapacity;
}

int cargo :: getCargoCapacity(){
    return cargoCapacity;
}

cargo :: ~cargo(){}

double cargo :: calculateEfficiency(){
    return (((this->getWeight() + this->cargoCapacity)/ this->getPowerDrain())/ this->getCost());
}