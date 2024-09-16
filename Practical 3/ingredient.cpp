#include <string>
#include "ingredient.h"

using namespace std;

ingredient :: ingredient(string name, int dangerRating){//constructs class using the passed variables
    this->name = name;
    this->dangerRating = dangerRating;
}
ingredient :: ingredient(const ingredient* newIngredient){//copy constructor for class. Creates new instance of class using passed arguements.
    name = newIngredient->name;
	dangerRating = newIngredient->dangerRating;
}

ingredient :: ingredient(const ingredient& newIngredient){//Copy constructor for class. Create new instance of calss using passed arguement.
    name = newIngredient.name;
	dangerRating = newIngredient.dangerRating;
}

ingredient :: ~ingredient(){ //default destructor for the class
}

int ingredient :: getDanger(){//getter for dangerRating
    return dangerRating;
}

string ingredient :: getName(){//getter for name variable
    return name;
}