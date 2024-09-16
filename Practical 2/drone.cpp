#include <iostream>
#include <string>
#include "drone.h"


using namespace std;

drone :: drone(string name,string type,int hp,double energy){
    this->name = name;
    this->type = type;
    this->hp = hp;
    this->energy = energy;
}

drone :: ~drone(){
    cout << name << " deleted" << endl;
}

string drone :: getName(){
    return name;
}

string drone :: getType(){
    return type;
}


int drone :: getHP(){
    return hp;
}

double drone :: getEnergy(){
    return energy;
}

void drone :: print(){
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "HP: " << hp << endl;
    cout << "Energy: " << energy << endl;

}