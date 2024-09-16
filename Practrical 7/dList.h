#ifndef dList_h
#define dList_h

#include <cstdlib>
#include "dispatch.h"
#include "train.h"
#include "trainCar.h"

using namespace std;

class dList;
ostream& operator<<(ostream&, const dList&);

class dList{
private:
    dispatch* head;
    int size;
    int rS;

public:
    dList(int);
    ~dList();
    dispatch* getHead() const;
    int getSize() const;
    dispatch* getItem(int);
    string firstOrder();
    friend ostream& operator<< (ostream& ,const dList&);
    void addOrder(string);
    void validateTrain();
    void shuffleOrders();
};

#endif