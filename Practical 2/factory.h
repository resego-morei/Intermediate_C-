#ifndef FACTORY_H
#define FACTORY_H

//libriaries
#include <string>
#include "drone.h"

using namespace std;
class factory{
    private:
        drone** list;
        string fID;
        string oID;
        int level;
        int droneLimit;
        int currNumDrones;

    public:
        factory(string fID, string oID, int droneLimit);
        factory(string fID, string oID, drone** drones, int droneLimit, int currNumDrones);
        ~factory();
        void levelUp();
        int addDrone(drone* d);
        int removeDrone(string name);
        string getFID();
        string getOID();
        int getCurrSize();
        int getLimit();
        void printDrones(string s);

};

#endif