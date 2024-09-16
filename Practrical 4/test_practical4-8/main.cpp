/*#include "tome.h"
#include <cstring>
#include <string>
#include <iostream>

using namespace std;


int main()
{

	string l[10]  = {"Hex Curse", "Summon Ice Golem"};
    string h[10]  = {"Hell Fire", "Volcano ash", "Eternal flames"};
    string x[10];
    tome t("Hexes and Incantations, A Study", 2,"S. Swaddles, D. Pines",l);
    tome c("Plutto ", 2,"S. Swaddles, D. Pines",h);
    tome b("Maximum carnage ", 0,"S. Swaddles, D. Pines",l);
    
  b = c;
  c = c +"Hex Curse";
  cout << c;
  cout << b;

  b = b+"CRazy Spells ";
  cout << b;
    	
	
return 0;	
}*/

#include <iostream>
#include <string>
#include "tome.h"
using namespace std;

int main(int argc, char const *argv[])
{
    cout<<"............................................................"<<endl;
    cout<<".....Testing the Default Constructor........................"<<endl;
    tome object_def();
    cout<<object_def;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the Constructor And the << operator............"<<endl;
    string my_array[6] = {"chick", "", "beef","hungry","hie"};
    tome object("Tshego Tome",6,"Resego",my_array);
    cout<<object;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the get functions.............................."<<endl;
    cout<<object.getAuthor()<<endl;
    cout<<object.getName()<<endl;
    cout<<object.getSpell(2)<<endl;
    cout<<object.getTomeSize()<<endl;
    cout<<"............................................................"<<endl;
    cout<<".....Expected Output........................................"<<endl;
    cout<<"Resego"<<endl<<"Tshego Tome"<<endl<<"beef"<<endl<<"5"<<endl;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the +operator when there's an empty index......"<<endl;
    string k = "hide";
    object+k;
    cout<<object;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the +operator when there's no empty index......"<<endl;
    string p = "hiden";
    object+p;
    cout<<object;
    cout<<"......Adding the same string until the array is full........"<<endl;
    string u = "hiden2";
    object+u;
    object+u;
    object+u;
    object+u;
    object+u;
    object+u;
    object+u;
    object+u;
    object+u;
    cout<<object;
    cout<<"............................................................"<<endl;
    cout<<".....It Shouldn't crash up to this far for the +operator...."<<endl;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the -operator when there's no empty index......"<<endl;
    object-u;
    cout<<object;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the =operator with two objects................."<<endl;
    tome object_second("Tshego Tome",6,"Resego",my_array);
    object_second=object;
    cout<<object_second;
    cout<<object;
    cout<<".....It should print the same thing twice since we copied..."<<endl;
    cout<<"............................................................"<<endl;
    cout<<".....Testing the ==operator with two objects................"<<endl;
    bool temp_bool = object_second==object;
    cout<<".....It Should be true [1].................................."<<endl;
    cout<<temp_bool<<endl;
    cout<<".....It Should be false now [0]............................."<<endl;
    tome object_third("Tshego Tome",6,"Resego",my_array);
    temp_bool = object==object_third;
    cout<<temp_bool<<endl;
    cout<<".....Done Testing For Now (*_*)............................."<<endl;
    return 0;
}