#ifndef TRAIN_H
#define TRAIN_H
#include "component.h"
#include <string>

using namespace std;

class train{
private:
    int trainSize;
    component** design;
public:
    train(int);
    ~train();
    friend ostream& operator<<(ostream&, const train&);
    int addComponent(string);
    int removeComponent();
};

#endif