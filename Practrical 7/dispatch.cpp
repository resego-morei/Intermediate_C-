#include "dispatch.h"
#include <iostream>

 dispatch::dispatch(std::string o){
     order = o;
     next = NULL;
 }

 dispatch::~dispatch(){
     std::cout << getOrder();
     std::cout << " processed";
     std::cout << std::endl;

 }

std::string  dispatch::getOrder(){
    return order;
}