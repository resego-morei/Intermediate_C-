#ifndef MSGQUEUE_H
#define MSGQUEUE_H

#include <iostream>
#include "msgNode.h"

using namespace std;

template <class T>
class msgQueue{
    private:
        msgNode<T>* head;
        msgNode<T>* tail;
    public:
        msgQueue();
        ~msgQueue();
        void enqueue(msgNode<T>*);
        void dequeue();
        msgNode<T>* peek();
        void print();
        void compileMessageData();
};
#endif