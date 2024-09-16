#ifndef TOOSLOW_H
#define TOOSLOW_H
#include <exception>
#include <iostream>

class tooSlow: public std::exception{
public:
    const char* what() const throw(){
        return "TOO SLOW";
    }
};

#endif