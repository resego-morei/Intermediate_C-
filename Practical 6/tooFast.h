#ifndef TOOFAST
#define TOOFAST
#include <exception>
#include <iostream>

class tooFast: public std::exception{
public:
    const char* what() const throw(){
        return "SPEED LIMIT EXCEEDED";
    }
};

#endif