#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>

class ingredient{
    private:
        string name;
        int dangerRating;
    
    public:
        ingredient(string name, int dangerRating);
        ingredient(const ingredient* newIngredient);
        ingredient(const ingredient& newIngredient);
        ~ingredient();
        int getDanger();
        string getName();
};

#endif