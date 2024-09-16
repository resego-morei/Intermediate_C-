#ifndef train_h
#define train_h

#include <sstream>
#include "trainCar.h"

class train{
private:
    trainCar* head;
    int size;

public:
    train(std::string);
    ~train();
    int calcTotalCost();
    void addCar(int);
};

#endif