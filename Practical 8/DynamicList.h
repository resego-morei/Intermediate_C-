#ifndef DynamicList_h
#define DynamicList_h

#include <iostream>
#include "Node.h"

template <class T>
class DynamicList;

template <class T >
std::ostream& operator<<(std::ostream& output, const DynamicList<T>& list);


template <class T>
class DynamicList{
private:
    Node<T>* head;
public:
    DynamicList();
    ~DynamicList();
    Node<T>* getHeadNode();
    T operator[](const int);
    bool deleteNode(T);
    bool insertNodeAt(const int, const T);
    bool operator==(const DynamicList<T>& );
    int getSize() const;
    friend std::ostream& operator<<<T>(std::ostream&, const DynamicList<T>&);
    void operator+=(const DynamicList<T>& );
    void operator+=(const T);
};


#endif