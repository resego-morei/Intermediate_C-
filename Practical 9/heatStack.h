#ifndef HEATSTACK_H
#define HEATSTACK_H

#include <iostream>
#include "heatNode.h"

using namespace std;

template <class T>
class heatStack{
    private:
        int stackSize;
        heatNode<T>** stack;
    public:
        heatStack();
        ~heatStack();
        void push(heatNode<T>*);
        void pop();
        heatNode<T>* peek();
        void print();
        bool validateCooling(int*, int);
};

#endif