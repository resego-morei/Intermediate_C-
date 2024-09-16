#include "dList.h"

using namespace std;

dList::dList(int rS){
    this->rS = rS;
    head = NULL;
    srand(rS);
    size = 0;
}

dList::~dList(){
    if(this->head != NULL){
        dispatch* nodePtr = this->head;
        dispatch* nextNode;

        while (nodePtr != NULL){
            nextNode = nodePtr->next;
            delete nodePtr;
            nodePtr = nextNode;
        }
    }
}


dispatch* dList::getHead() const{
    return head;
}

int dList::getSize() const{
    return size;
}

dispatch* dList::getItem(int i){
    dispatch* nodePtr= head;

    if(i > size || i < 0)
        return NULL;

    else{
        for(int x = 0; x < this->size; x++){
            if(x == i)
                return nodePtr;

            nodePtr = nodePtr->next;
        }
    }

    return nodePtr;
}

string dList::firstOrder(){
    string value;
    dispatch* nodePtr = this->head;
    dispatch* find = this->head;

    if (this->head == NULL)
        return 0;

    while (nodePtr){
        if (nodePtr->getOrder() < find->getOrder()){
            value = nodePtr->getOrder();
            find = nodePtr;
        }
        nodePtr = nodePtr->next;
    }
    return value;
}

ostream& operator<<(ostream& output, const dList& t){
    dispatch *nodePtr = t.head;
    int count = 1;
    if(!nodePtr)
        return output;
    
    else{
        while(nodePtr){
            output << nodePtr->getOrder(); 
            if(count < t.size)
                output << ",";

            nodePtr = nodePtr->next;
            count++;
        }
        output << endl;
    }
    return output;
}

void dList::addOrder(string newOrder){
    dispatch *nodePtr = head;

    if(!nodePtr){
        this->head = new dispatch(newOrder);
        this->size++;
    }

    else if(newOrder <= this->firstOrder()){
        if(nodePtr){
            while(nodePtr->next)
                nodePtr = nodePtr->next;
            
            nodePtr->next = new dispatch(newOrder);;
            this->size++;
        }
    }

    else{
        dispatch *nodeObject = new dispatch(newOrder);
        nodeObject->next = head;
        this->head = nodeObject;
        this->size++;
    }
}


void dList::validateTrain(){
    dispatch* current = head;
    dispatch* previous = NULL;
    
    if(current){
        current = this->head->next;
        previous = this->head;
        this->head = current;


        train* newObject = new train(previous->getOrder());

        if(newObject->calcTotalCost() < 50)
            cout << "Valid" << endl;

        else
            cout << "Invaild" << endl;
        
        delete previous;
        previous = NULL;

        delete newObject;
        newObject = NULL;
    }

    else
        cout << "Invaild" << endl;
}

void dList::shuffleOrders(){
    if (!this->head)
        return;

    dispatch* current = this->head;
    dispatch* nodePtr = this->head;

    int s = 0,
        randomNum = rand()% this->size;

    while(s < randomNum){
        current = current->next;
        s++;
    }

    if (current == nodePtr)
        return;

    else if (current->next == NULL){
        int count = this->size - 1, 
            i = 1;

        while (i < count){
            nodePtr = this->head->next;
            i++;
        }

        nodePtr->next = NULL;
        nodePtr = this->head;
        this->head = current;
        current->next = nodePtr;
    }

    else{
        nodePtr = this->head;
        dispatch* temp = current;
        int count = this->size,
            j = randomNum;

        while (j < (count - 1)){
            current = current->next;
            j++;
        }
        current->next = nodePtr;
        
        j = 1;
        while(j < randomNum){
            nodePtr = this->head->next;
            j++;
        }
        nodePtr->next = NULL;
        this->head = temp;
    }  
}