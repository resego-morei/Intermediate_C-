#ifndef TROLLEY_H
#define TROLLEY_H
#include <string>

using namespace std;

class trolley{
    private:
        int speed;
        string name;
    public:
        trolley();
        ~trolley();
        trolley(string);
        int getSpeed();
        void increaseSpeed(int);
};

#endif