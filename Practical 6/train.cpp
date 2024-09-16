#include "train.h"
#include "storageFull.h"
#include "storageEmpty.h"
#include <iostream>
//#include <typeinfo>

template <class T>
train<T> :: train(){ }

template <class T>
train<T> :: ~train(){
    cout << "Dispatch Name: ";
    cout << getName();
    cout << endl;

    cout << "Current Storage: ";
    cout << getCurrCargo();
    cout << endl;

    cout << "Storage Max: ";
    cout << getCargoCap();
    cout << endl;
}

template <class T>
train<T> :: train(string name, T storageCap){
    this->currStorage = 0;
    this->name = name;
    this->storageCap = storageCap;
}

template <class T>
string train<T> :: getName(){
    return this->name;
}

template <class T>
void train<T> :: loadCargo(T cargo){
    if(this->currStorage + cargo <= storageCap)
        this->currStorage += cargo;
    else
        throw storageFull(); 

    cout << "Capacity: ";
    cout << this->currStorage;
    cout << endl;
}

template <class T>
void train<T> :: unloadCargo(T cargo){
    if(this->currStorage < cargo)
        throw storageEmpty();
    
    else if(this->currStorage >= cargo)
        this->currStorage -= cargo;

    cout << "Capacity: ";
    cout << this->currStorage;
    cout << endl;
} 

template <class T>
T train<T> :: getCargoCap(){
    return this->storageCap;
}

template <class T>
T train<T> :: getCurrCargo(){
    return this->currStorage;
}