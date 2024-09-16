#include "msgNode.h"

template <class T>
msgNode<T>::msgNode(T i, int s){
    this->message = i;
    this->size = s;
}

template <class T>
msgNode<T>::~msgNode(){
    std::cout << "Message Processed";
    std::cout << std::endl;
}

template <class T>
T msgNode<T>::getMessage() const{
    return this->message;
}

template <class T>
int msgNode<T>::getSize() const{
    return this->size;
}