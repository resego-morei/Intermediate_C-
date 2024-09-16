#ifndef dispatch_h
#define dispatch_h

#include <iostream>
#include <string>


class dispatch{
private:
    std::string order;

public:
    dispatch(std::string);
    ~dispatch();
    std::string getOrder();
    dispatch* next;
};


#endif