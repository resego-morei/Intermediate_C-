#include <iostream>
#include "train.h"

int main(int arg, const char * argv[]){
    std::cout<<"......... Testing The Constructor For The Train Class ..........."<<std::endl;
    train * myTrain = new train(10);
    std::string firstC = "c,3.455,4.56765,10,89";
    std::string secondC = "l,4.322,10.34232,56,34";
    std::string thirdC = "p,8.765,6.567,45,33";
    std::string fourthC = "c,6.79980,8.9908,78,98";
    std::string fifthC = "l,5.667,9.5355,97,655";
    std::string sixthC = "c,9.79980,76.9908,56,92";
    std::string seventhC = "c,9.667,6.5355,7,655";
    std::string eightthC = "p,3.667,5.5355,67,69";
    std::string ninethC = "p,33.667,2.5355,70,45";
    std::string tenthC = "l,8.667,8.5355,50,55";
    std::string eleventhC = "l,2.667,3.5355,23,39";
    std::cout<<"...... Testing The AddComponent Func For The Train Class ......"<<std::endl;
    /**************************************************************************************/
    /*** If It Crashes Along the wayb, Check which Constructor Caused the Code To Crash ***/
    /****************************   It Shouldn't Crash   **********************************/
    /**************************************************************************************/
    std::cout<<myTrain->addComponent(firstC)<<std::endl;
    std::cout<<myTrain->addComponent(secondC)<<std::endl;
    std::cout<<myTrain->addComponent(thirdC)<<std::endl;
    std::cout<<myTrain->addComponent(fourthC)<<std::endl;
    std::cout<<myTrain->addComponent(fifthC)<<std::endl;
    std::cout<<myTrain->addComponent(sixthC)<<std::endl;
    std::cout<<myTrain->addComponent(seventhC)<<std::endl;
    std::cout<<myTrain->addComponent(eightthC)<<std::endl;
    std::cout<<myTrain->addComponent(ninethC)<<std::endl;
    std::cout<<myTrain->addComponent(tenthC)<<std::endl;
    std::cout<<"................... Testing Your Operator<< ..................."<<std::endl;
    std::cout<<*myTrain<<std::endl;
    std::cout<<"....... Now Adding Another Component On The 11th Index ........"<<std::endl;
    std::cout<<"...................... Out Of Bounds! ........................."<<std::endl;
    /**************************************************************************************/
    /********* If It Crashes Here, You Most Probably Saw Fire, It Shouldn't Crash *********/
    /**************************************************************************************/
    std::cout<<myTrain->addComponent(eleventhC)<<std::endl;
    std::cout<<"........ Printing the summary, After the Silly Attempt ........"<<std::endl;
    std::cout<<*myTrain<<std::endl;
    std::cout<<".... Testing The removeComponent Func For The Train Class ....."<<std::endl;
    /**************************************************************************************/
    /*** If It Crashed , You Probably Didn't set The Array Index to NULL After Deleting ***/
    /**************************************************************************************/
    std::cout<<myTrain->removeComponent()<<std::endl;
    std::cout<<myTrain->removeComponent()<<std::endl;
    std::cout<<".......... Done Removing, Printing The Summary Again .........."<<std::endl;
    std::cout<<*myTrain;
    std::cout<<".............. Adding Components Back To The Array ............"<<std::endl;
    std::cout<<myTrain->addComponent(firstC)<<std::endl;
    std::cout<<myTrain->addComponent(secondC)<<std::endl;
    std::cout<<"....................... S U M M A R Y ........................."<<std::endl;
    std::cout<<*myTrain;
    std::cout<<"................... D O N E   T E S T I N G ..................."<<std::endl;
    std::cout<<".................... The Destructor Now ......................."<<std::endl;
    delete myTrain;
    return 0;
}
//Expected Output
/*
./main
......... Testing The Constructor For The Train Class ...........
...... Testing The AddComponent Func For The Train Class ......
0
1
2
3
4
5
6
7
8
9
................... Testing Your Operator<< ...................
DESIGN: clpclccppl
Efficiency Rating: 27.6693
Cargo Cars: 4
Passenger Cars: 3
Locomotives: 3

....... Now Adding Another Component On The 11th Index ........
...................... Out Of Bounds! .........................
-1
........ Printing the summary, After the Silly Attempt ........
DESIGN: clpclccppl
Efficiency Rating: 27.6693
Cargo Cars: 4
Passenger Cars: 3
Locomotives: 3

.... Testing The removeComponent Func For The Train Class .....
0
1
.......... Done Removing, Printing The Summary Again ..........
DESIGN: pclccppl
Efficiency Rating: 25.6452
Cargo Cars: 3
Passenger Cars: 3
Locomotives: 2
.............. Adding Components Back To The Array ............
0
1
....................... S U M M A R Y .........................
DESIGN: clpclccppl
Efficiency Rating: 27.6693
Cargo Cars: 4
Passenger Cars: 3
Locomotives: 3
................... D O N E   T E S T I N G ...................
.................... The Destructor Now .......................
Number of Cargo Cars: 4
Number of Passenger Cars: 3
Number of Locomotivess: 3*/