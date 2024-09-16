#ifndef MSGNODE_H
#define MSGNODE_H

#include <iostream>

template <class T>
class msgNode{
    private:
        T message;
        int size;
    public:
        msgNode* next;
        msgNode* prev;
        msgNode(T, int);
        ~msgNode();
        T getMessage() const;
        int getSize() const;
};
#endif