#include "train.h"

train::train(std::string config){
    this->size = 0;
    std::string content;
    int pos, tempCost,
        ptrCursor = 1, count = 0; 
    std::stringstream ss;
    trainCar* nodePtr;
    long unsigned int i = 0;

    while( i < config.size()){
        if(config[i] == ',')
            count++;
        i++;
    }

    if(count > 0){
        pos = config.find(',');
        content = config.substr(0, pos);
        config.erase(0,(pos+1));
        ss.clear();
        ss << content;
        ss >> tempCost;
        this->head = new trainCar(tempCost);
        
        this->size++;
        nodePtr = this->head;
        tempCost = 0;

    
        while(ptrCursor < count){
            pos = config.find(',');
            content = config.substr(0, pos);
            config.erase(0,(pos+1));

            ss.clear();
            ss << content;
            ss >> tempCost;
            nodePtr->next = new trainCar(tempCost);
            this->size++;
            
            nodePtr = nodePtr->next;
            ptrCursor++;
            tempCost = 0;
        }
        
        ss.clear();
        ss << config;
        ss >> tempCost;
        nodePtr->next = new trainCar(tempCost);
        this->size++;
        nodePtr = nodePtr->next;
    }

    else{
        ss.clear();
        ss << config;
        ss >> tempCost;
        this->head = new trainCar(tempCost);
        this->size++;
    }

}

train::~train(){
    while(this->head){
        trainCar* nodePtr = head;
        this->head = this->head->next;
        delete nodePtr;
    }
   
}

int train::calcTotalCost(){
    int total = 0;
    trainCar* nodePtr = this->head;

    while(nodePtr){
        total += nodePtr->getCost();
        nodePtr = nodePtr->next;
    }
    
    std::cout << "Total Train Cost: ";
    std::cout << total;
    std::cout << std::endl;

    return total;
}

void train::addCar(int newCost){
    trainCar* nodePtr = head;

    if(nodePtr){
        while(nodePtr->next) //traverses to the last node
            nodePtr = nodePtr->next;
        
        nodePtr->next = new trainCar(newCost);
    }
    
    else if(!nodePtr){
        this->head = new trainCar(newCost);
        this->size++;
    }
    
}