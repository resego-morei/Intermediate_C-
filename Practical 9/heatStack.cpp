#include "heatNode.h"
#include "heatStack.h"

template <class T>
heatStack<T>::heatStack(){
    this->stackSize = 0;
    this->stack = new heatNode<T>*[this->stackSize];
}

template <class T>
heatStack<T>::~heatStack(){
    for(int x = 0; x < this->stackSize; x++) delete this->stack[x];
    delete [] this->stack;
    this->stack = NULL;
}

template <class T>
void heatStack<T>::push(heatNode<T>* t){
    heatNode<T>* temp = new heatNode<T>*[stackSize];
    

    


}

template <class T>
void heatStack<T>::pop(){
    if(!this->stack){
        cout << "EMPTY";
        cout << endl;
    }
    else{
        for(int i = 0; i < this->stackSize; i++){
            stack[i] = stack[++i];
            delete stack[i];
            --stackSize;
            break;
        }
    }
}

template <class T>
heatNode<T>* heatStack<T>::peek(){
}

template <class T>
void heatStack<T>::print(){
    if(this->stack){
        for(int i = 0; i < this->stackSize; i++){
            cout << "Heat Sink CL: ";
            cout << this->stack[i]->getCoolantLevel();
            cout << endl;
        }
    }
}