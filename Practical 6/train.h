#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <iostream>
//#include <typeinfo>
#include "storageEmpty.h"
#include "storageFull.h"

using namespace std;

template <class T> 
class train{
    private:
        T currStorage;
        T storageCap;
        string name;
        
    public:
        train();
        ~train();
        train(string, T);
        string getName();
        T getCargoCap();
        T getCurrCargo();
        void loadCargo(T);
        void unloadCargo(T);        
};
#include "train.cpp"
#endif