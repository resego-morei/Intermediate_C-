#include "manager.h"
#include "storageEmpty.h"
#include "storageFull.h"
#include <fstream>
#include <sstream>
#include<iostream>

using namespace std;

template <class T>
manager<T>::manager(string input){     
    ifstream text;
    string line;
    // char comma;
    int x, y = 0;
    text.open(input.c_str());
    text >> this->numTrains;
    this->trains = new train<T> *[numTrains];

    while(text >> line){
        stringstream ss(line);
        getline(ss, line, ',');
        ss >> x;
        this->trains[y] = new train<T>(line, x);
        y++;
    }
   
    text.close(); 
}

template <class T>
manager<T>:: ~manager(){
    int i;
    for(i = 0; i < this->numTrains; i++)
        delete trains[i];
    delete [] trains;

}

template <class T>
void manager<T>::summarise(){
    int i, temp = 0;
    cout << "Total Current Storage: ";
    for(i = 0; i < this->numTrains; i++){
        if(this->trains[i] != NULL)
            temp += trains[i]->getCurrCargo();
    }
    cout << temp;
    cout << endl;
}

template <class T>
void manager<T>::loadTrain(int i, T load){
    if(i < this->numTrains && trains[i] != NULL)
        trains[i]->loadCargo(load);
}