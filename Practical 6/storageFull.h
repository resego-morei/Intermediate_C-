#ifndef STORAGEFULL_H
#define STORAGEFULL_H
#include <exception>
#include <iostream>

class storageFull: public std::exception{
public:
    const char* what() const throw(){
        return "STORAGE FULL";
    }
};

#endif