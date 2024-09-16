#ifndef STORAGEEMPTY_H
#define STORAGEEMPTY_H
#include <iostream>
#include <exception>

class storageEmpty: public std::exception{
public:
    const char* what() const throw(){
        return "STORAGE EMPTY";
    }
};

#endif