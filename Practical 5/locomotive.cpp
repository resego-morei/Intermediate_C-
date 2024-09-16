#include <cmath>
#include <iostream>
#include "locomotive.h"
#include "component.h"

using namespace std;

locomotive :: locomotive(char type, double weight, double cost, int powerDrain, int powerGen) : component(type,weight,cost,powerDrain){
    this->powerGen = powerGen;
}
int locomotive :: getPowerGen(){
    return powerGen;
}

locomotive :: ~locomotive(){}

double locomotive :: calculateEfficiency(){
    return ((this->powerGen/this->getPowerDrain())/this->getCost());
}