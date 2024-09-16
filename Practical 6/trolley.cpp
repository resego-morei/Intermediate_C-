#include "trolley.h"
#include "tooSlow.h"
#include "tooFast.h"
using namespace std;

trolley :: trolley(){ }
trolley :: ~trolley(){ }

trolley :: trolley(string name){
    this->speed = 0;
    this->name = name;
}

int trolley :: getSpeed(){
    return this->speed;
}

void trolley :: increaseSpeed(int s){
    this->speed += s;
} 