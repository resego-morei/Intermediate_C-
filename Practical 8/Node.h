#ifndef Node_h
#define Node_h

#include <iostream>

template <class T>
class Node{
public:
    Node(T);
    ~Node();
    Node<T>* next;
    Node<T>* prev;
    T* value;
};

#endif