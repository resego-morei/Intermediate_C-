/*#include <iostream>
#include <string>
#include "factory.h"
#include "drone.h"

using namespace std;

int main()
{

  drone *l = new drone("hydra", "fire", 5, 5700);
  drone *m = new drone("pete", "air", 30, 400);
  drone *n = new drone("seth", "water", 2, 10);
  drone *o = new drone("mike", "fire", 39, 4500);
  drone *p = new drone("steve", "earth", 11, 3900);

  factory *KM = new factory("202", "596", 6);

  KM->levelUp();

  KM->addDrone(l);
  KM->addDrone(m);
   KM->addDrone(n);
    KM->addDrone(o);

  cout<<KM->removeDrone("seth")<<endl;
  cout<<KM->addDrone(p)<<endl;


  KM->printDrones("hp");

  return 0;
}
*/
#include <iostream>
#include <string>
#include "drone.h"
#include "factory.h"
using namespace std;
void myFunc(){
	cout<<"A"<<endl;
	string B="ZXCVBNM";
	drone** drones = new drone*[5];
	drones[0] = new drone("May","test",12,5.8);
	drones[1] = new drone("June","test",11,5.9);
	drones[2] = new drone("August","test",10,5.6);
	drones[3] = new drone("September","test",14,6.6);
	drones[4] = new drone("November","test",13,5.4);
	cout<<"A"<<endl;
	factory* testfactory= new factory("Test factory","id",drones,10,5);
	cout<<"A"<<endl;
	for(int i=0;i<5;i++){
		cout<<"A"<<endl;
	}
	
	for(int i=0;i<5;i++){
		delete drones[i];
	}
	delete [] drones;	
	testfactory->printDrones("m");
}
int main(){
	myFunc();
	return 0;
}