#include "train.h"
#include "component.h"
#include "cargo.h"
#include "passenger.h"
#include "locomotive.h"
#include <iostream>
#include <sstream>

using namespace std;

train :: train(int size){
    this->trainSize = size;
    this->design = new component*[size];

    for(int i = 0; i < this->trainSize; i++){
        if (design[i] != NULL)
            design[i] = NULL;
        else
            continue;
    }
}

train :: ~train(){
    int i = 0, c = 0,
    p = 0, l = 0;

    cout << "Number of Cargo Cars: ";
    for(i = 0; i < this->trainSize; i++){
        if(this->design[i]!= NULL && this->design[i]->getType() == 'c')
            c++;
        else 
            continue;
    }
    cout << c;
    cout << endl;
   
    cout << "Number of Passenger Cars: ";
    for(i = 0; i < this->trainSize; i++){
        if(this->design[i] != NULL && this->design[i]->getType() == 'p')
            p++;
        else 
            continue;
    }
    cout << p;
    cout << endl;
    
    cout << "Number of Locomotives: ";
    for(i = 0; i < this->trainSize; i++){
        if(this->design[i] != NULL && this->design[i]->getType() == 'l')
            l++;
        else 
            continue;
    }
    cout << l;
    cout << endl;

    for (i = 0; i < this->trainSize; i++) 
        delete this->design[i]; 
    delete [] this->design;
    design = NULL;
}

ostream& operator<<(ostream& output, const train& t){
    int i,
        c = 0, p = 0, l = 0;
    double temp_total = 0.0;

    output << "DESIGN: ";
    for(i = 0; i < t.trainSize;i++){
        if(t.design[i] != NULL)
            output << t.design[i]->getType();
        else 
            continue;
    }
        
    output << endl;

    output << "Efficiency Rating: ";
    for(i = 0; i < t.trainSize; i++){
        if (t.design[i] != NULL)
            temp_total += t.design[i]->calculateEfficiency();       
    }
    output << temp_total;
    output << endl;

    output << "Cargo Cars: ";
    for(i = 0; i < t.trainSize; i++){
        if(t.design[i]!= NULL && t.design[i]->getType() == 'c')
            c++;
        else 
            continue;
    }
    output << c;
    output << endl;

    output << "Passenger Cars: ";
    for(i = 0; i < t.trainSize; i++){
        if(t.design[i] != NULL && t.design[i]->getType() == 'p')
            p++;
        else 
            continue;
    }
    output << p;
    output << endl;

    output << "Locomotives: ";
    for(i = 0; i < t.trainSize; i++){
        if(t.design[i] != NULL && t.design[i]->getType() == 'l')
            l++;
        else 
            continue;
    }
    output << l;
    output << endl;

    return output;
}

int train :: addComponent(string comp){
    
    char type;
    double weights, costs;
    char comma;
    int powerDrains, Capacity, i;

    stringstream tt(comp);
    tt>>type>>comma>>weights>>comma>>costs>>comma>>powerDrains>>comma>>Capacity;

    for(i = 0; i < this->trainSize; i++){
        if(this->design[i] == NULL){
            if(type == 'c'){
                this->design[i] = new cargo(type, weights, costs, powerDrains, Capacity);
                return i;
            }

            else if(type == 'p'){
                this->design[i] = new passenger(type, weights, costs, powerDrains, Capacity);
                return i;
            }

            else if(type == 'l'){
                this->design[i] = new locomotive(type, weights, costs, powerDrains, Capacity);
                return i;
            }
        }          
    }

    return -1;
}

int train :: removeComponent(){
    int i;

    for(i = 0; i < this->trainSize; i++){
        if (design[i] != NULL){
            delete design[i];
            design[i] = NULL;
            return i; 
        }
    }

    return -1;
}
