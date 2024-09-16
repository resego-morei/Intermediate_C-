#include "heatNode.h"
#include "msgNode.h"

template <class T>
heatNode<T>::heatNode(T i, int p){
    this->coolantLevel = i;
    this->power = p;
}

template <class T>
heatNode<T>::~heatNode(){
    std::cout << "Heat Sink Removed";
    std::cout << std::endl;
}

template <class T>
T heatNode<T>::getCoolantLevel() const{
    return this->coolantLevel;
}

template <class T>
int heatNode<T>::getPower() const{
    return this->power;
}