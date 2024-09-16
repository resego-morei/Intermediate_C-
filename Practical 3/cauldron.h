#ifndef CAULDRON_H
#define CAULDRON_H
#include<string>
#include "ingredient.h"

using namespace std;

class cauldron{
    private:
        ingredient** ingredients;
        int numIngredients;
        int maxIngredients;

    public:
        cauldron(string ingredientList, int maxIngredients);
        cauldron(const cauldron* oldCauldron);
        void operator = (const cauldron& oldCauldron);
        ~cauldron();
        void print();
        int getMax() const;
        int getCurr() const;
        ingredient* getIngredient(int a) const;
        int addIngredient(string in, int dR);
        void removeIngredient(int in);
        void distillPotion(cauldron& currCauldron, string* list, int numRemove);
        void listIngredients();
};
#endif