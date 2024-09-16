#include "trainCar.h"

trainCar::trainCar(int c): cost(c){
    this->next = NULL;
}

trainCar::~trainCar(){
    std::cout << getCost();
    std::cout << " removed";
    std::cout << std::endl;
}

int trainCar::getCost(){
    return cost;
}