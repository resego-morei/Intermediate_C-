#include "Node.h"
#include <cstdlib>

using namespace std;

template <class T>
Node<T>::Node(T val){
    next = NULL;
    prev = NULL;

    this->value = new T(val);
}

template <class T>
Node<T>::~Node(){
    delete this->value;
    this->value = NULL;
}

template class Node<int>;