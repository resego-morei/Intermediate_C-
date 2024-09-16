#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include "storageEmpty.h"
#include "storageFull.h"
#include "train.h"
#include <string>

using namespace std;

template <class T> 
class manager{
    private:
        train<T> **trains;
        int numTrains;
        
    public:
        manager(string);
        ~manager();
        void summarise();
        void loadTrain(int, T);     
};

#include "manager.cpp"
#endif