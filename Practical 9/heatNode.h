#ifndef HEATNODE_H
#define HEATNODE_H

#include <iostream>

using namespace std;

template<class T>
class heatNode{
    private:
        T coolantLevel;
        int power;
    public:
        heatNode(T, int);
        ~heatNode();
        T getCoolantLevel() const;
        int getPower() const;
};
#endif