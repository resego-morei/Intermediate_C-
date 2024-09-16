#include "msgNode.h"
#include "msgQueue.h"

template <class T>
msgQueue<T> :: msgQueue(){
    this->head = NULL;
    this->tail = NULL;
}

template <class T>
msgQueue<T> :: ~msgQueue(){
    while(head)
        dequeue();
}

template <class T>
void msgQueue<T>::enqueue(msgNode <T>* t){
    msgNode<T> *newNode;
    if(!head){
        newNode = t;
        this->head = newNode;
        this->tail = newNode;
    }

    newNode = t;
    this->tail->next = newNode;
    this->tail = newNode;
  
}

template <class T>
void msgQueue<T>::dequeue(){
    msgNode<T>* nodePtr;
    if (!this->head){
        cout << "EMPTY";
        cout << endl;
        return;
    }

    else{
        nodePtr = this->head->next;
        delete this->head;
        this->head = nodePtr;
    }
}

template <class T>
msgNode<T>* msgQueue<T>::peek(){
    if(this->head)    return this->head;
    else    return NULL;
}

template <class T>
void msgQueue<T>::print(){
    msgNode<T>* nodePtr = this->head;

    if(this->head){
        int count = 0; 
        while (nodePtr){
            cout << "Message ";
            cout << count;
            cout << " [Size: ";
            cout << nodePtr->getSize();
            cout << "]";
            cout << endl;
            nodePtr = nodePtr->next;
            count++;
        }
    }
}

template <class T>
void msgQueue<T>::compileMessageData(){
    msgNode<T>* nodePtr = this->head;

    double total = 0;
    int count = 0;
    while (nodePtr){
        total+=nodePtr->getSize();
        nodePtr=nodePtr->next;
        count++;
    }

    cout << "Total Number of Messages: ";
    cout << count;
    cout << endl;

    if (total < 1000){
        cout << "Size: ";
        cout << total;
        cout << "KB";
        cout << endl;
    }
        
    else if (1000 >= total || total < 1000000){
        cout << "Size: ";
        cout << (total/1000);
        cout << "MB";
        cout << endl;
    }
        
    else{
        cout << "Size: ";
        cout << (total/1000000);
        cout << "GB";
        cout << endl;
    }
}