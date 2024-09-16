#ifndef COMPONENT_H
#define COMPONENT_H

class component{
private:
    double weight;
    int powerDrain;
    double cost;
    char type;

public:
    component();
    component(char, double, double, int);
    double getWeight();
    double getCost();
    int getPowerDrain();
    char getType();
    virtual ~component();
    virtual double calculateEfficiency();
};

#endif