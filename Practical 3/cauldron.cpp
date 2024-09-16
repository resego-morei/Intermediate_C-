#include <iostream>
#include <fstream>
#include <sstream>
#include "cauldron.h"


using namespace std;

cauldron :: cauldron(string ingredientList, int maxIngredients){// Basic Constructor: Recieves string (name of file): Maximum number of ingredients: 
    this->maxIngredients = maxIngredients;
    ingredients = new ingredient * [maxIngredients];

    
    fstream ingredientTextfile(ingredientList);
    
	ingredientTextfile.open ("data.txt");
	if(ingredientTextfile.fail())
        cout << "Error: File not open!" << endl;
    else{
        int count_Comma, lineinput = 0,State;
        string read, pos, point;
		
			getline(ingredientTextfile, pos);
			pos += ",";
			read = pos;
			do{
				State = read.find(",");
				point = read.substr(0 , State);
				read.erase(0 , (State + 1));
				count_Comma++;
					
			}while(read.length() > 0);

            //ingredients[lineinput] = count_Comma; //Find a way to store values from the file into the dynamic array.

            lineinput++;
            count_Comma = 0;

            
        }
	ingredientTextfile.close();
}



cauldron :: cauldron(const cauldron* oldCauldron){
    numIngredients = oldCauldron->numIngredients;
    maxIngredients = oldCauldron->maxIngredients;
    ingredients = oldCauldron->ingredients;
}

void cauldron :: operator = (const cauldron& oldCauldron){
    ingredients = oldCauldron.ingredients;
}

cauldron :: ~cauldron(){
    delete[] ingredients;
    ingredients = nullptr;
}
void cauldron :: print(){ //prints out summary of information
    cout << "Number of Ingredients: ";
        int total = 0;
        for(int i = 0; i < numIngredients; i++)
            total += numIngredients;
    cout << total << endl;

    cout << "Average Danger Rating: ";
    cout << ((ingredients[numIngredients]->getDanger())/total);
    cout << endl;


    cout << "Maximum Danger Rating: ";
        
    cout << "Minimum Danger Rating: ";

}
int cauldron :: getMax() const{
     return maxIngredients;
}
int cauldron :: getCurr() const{
    return numIngredients;
}
ingredient* cauldron :: getIngredient(int a) const{
    return ingredients[a];
}
int cauldron :: addIngredient(string in, int dR){

}
void cauldron :: removeIngredient(int in){
    delete ingredients[in];
}
void cauldron :: distillPotion(cauldron& currCauldron, string* list, int numRemove){

}
void cauldron :: listIngredients(){

}