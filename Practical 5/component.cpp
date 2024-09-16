#include <iostream>
#include "component.h"

using namespace std;

//default constructor for the component class: Does nothing
component::component(){}

component::component(char type, double weight, double cost, int powerDrain){
    this->type = type;
    this->weight = weight;
    this->cost = cost;
    this->powerDrain = powerDrain;
}

double component::getWeight(){
    return weight;
}
double component::getCost(){
    return cost;
}
int component::getPowerDrain(){
    return powerDrain;
}
char component::getType(){
    return type;
}

component::~component(){}

double component::calculateEfficiency(){
    return 0.0;
}