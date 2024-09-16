#include <iostream>
#include <string>
#include "factory.h"

using namespace std;

factory :: factory(string fID, string oID, int droneLimit){
    this->droneLimit = droneLimit;
    list = new drone*[droneLimit];
    this->fID = fID;
    this->oID = oID; 
    level = 1;
    this->currNumDrones = 0;
    
}

factory :: factory(string fID, string oID, drone** drones, int droneLimit, int currNumDrones){
    this->fID = fID;
    this->oID = oID;
    this->droneLimit = droneLimit;
    level = 1;
    list = new drone*[droneLimit];
    this->currNumDrones = currNumDrones;
  
    for(int i = 0; i < currNumDrones; i++)    //When submitted to fitchfork. I used currNumDrones instead of curr_Num_Drones. Would that cause the error.
        if(drones[i] != nullptr)
            list[i]= new drone(drones[i]->getName(),drones[i]->getType(),drones[i]->getHP(),drones[i]->getEnergy());
    
}

factory :: ~factory(){
    for(int i = 0; i < droneLimit; i++)
        if(list[i]!= nullptr)
            delete list[i]; 
    delete [] list;
    list = nullptr;

}

void factory::levelUp(){
    level++;
}

int factory :: addDrone(drone* d){ //Something wrong the addDrone Function.
    int value_returned = -1, HP_multiplied = d->getHP() * level;
    double energy_multiplied= d->getEnergy() * level;

    if(currNumDrones != droneLimit){
        for(int y = 0; y < droneLimit; y++){
            if(list[y]==nullptr){
                list[y] = new drone(d->getName(),d->getType(), HP_multiplied, energy_multiplied);
                currNumDrones++;
                return y;
                break;
            }
        }
    }return -1;
}

int factory :: removeDrone(string name){
    for(int y = 0; y < droneLimit; y++){
        if(list[y] != nullptr){
            if(list[y] -> getName() == name){
                delete list[y];
                list[y]=nullptr;
                currNumDrones--;
                return y;
                break;
            }
        }
    }return -1;

}

string factory :: getFID(){
    return fID;
}

string factory :: getOID(){
    return oID;
}

int factory :: getCurrSize(){
    return currNumDrones;
}

int factory :: getLimit(){
    return droneLimit;
}

void factory :: printDrones(string s){

    cout << "Factory ID: " << fID << endl;
    cout << "OID: " << oID << endl;
    cout << "Number of Drones: " << currNumDrones << endl;
    cout << "Drone Limit: " << droneLimit << endl;
    cout << "Rank: ";
    for(int i = 0; i < level; i++)
        cout << "*";
    cout << endl;

    double totalEnergy = 0;
    int y = 0;
    while (y < droneLimit){ //When I submitted on fitchfork. I did not put the droneLimit -1 to in parenthesis.
        if(list[y] != nullptr)
			totalEnergy += list[y]->getEnergy();   
        y++;
    } cout << "Energy Level: " << totalEnergy << endl;

    int * hpArray = new int[currNumDrones];
    int p = 0, d = 0;

    while (p < droneLimit){
        if(list[p]!=nullptr){
			hpArray[d] = list[p]->getHP();
            d++;
        }
        p++;   
    }
    /*for(int x = 0;x < currNumDrones; x++)
		    cout << hpArray[x] << " ";
	    cout<<endl;	
        */
    
    double *energyArray = new double[currNumDrones];
    p = 0;
    d = 0;

    while (p < droneLimit){
        if(list[p]!=nullptr){
			energyArray[d] = list[p]-> getEnergy();
            d++;
        }
        p++;   
    }

    if(s=="hp")
    {
        int temp;
        for(int i = 0; i < currNumDrones;i++)
        {		
		    for(int j=i+1;j<currNumDrones;j++)
            {
			    if(hpArray[i]>hpArray[j]) 
                {
				temp = hpArray[i];
				hpArray[i]=hpArray[j];
				hpArray[j]=temp;
			    }
		    }
	    }

        for(int k=0;k<currNumDrones;k++)
        {
            for(int p=0;p<droneLimit;p++)
            {
                if(list[p])
                {
                    if(hpArray[k]==list[p]->getHP())
                        cout<<list[p]->getName()<<endl;
                    
                }
            }
        }
        /*for(int x = 0;x < currNumDrones; x++)
		    cout << hpArray[x] << " ";
	    cout<<endl;*/
    }

    
    else if(s == "m")
    {
        double hold;
         for (int i = 0; i < currNumDrones; i++)
         {
            for (int j = 1 + i; j < currNumDrones; j++)
            {
                if (energyArray[i] < energyArray[j])
                {
                    hold = energyArray[i];
                    energyArray[i] = energyArray[j];
                    energyArray[j] = hold;
                }
            }
        }

        for(int k=0;k<currNumDrones;k++)
        {
            for(int p=0;p<droneLimit;p++)
            {
                if(list[p])
                {
                    if(energyArray[k]==list[p]->getEnergy())
                        cout<<list[p]->getName()<<endl;  
                }
            }
        }
    }

    delete [] hpArray;
    hpArray = nullptr;

    delete [] energyArray;
    energyArray = nullptr;  
}
