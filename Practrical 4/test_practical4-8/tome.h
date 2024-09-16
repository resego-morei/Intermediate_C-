#ifndef TOME_H
#define TOME_H

#include <string>

using namespace std;

class tome{
private:
   string references[10]; //array of string names that represent names of spells that reside in the tome: Each Separate Spell: Default state of array is to be populated by empty strings:
   string tomeName; // name of the tome as a string: 
   string author; // name of original authors of tome as represented by a string
   int currSpells; //current number of spells in the tome. It can be at most the maximum of 10 but never larger than it.

public:
    tome(string, string); //constructor (recieves number of arguments and instantiates them in class)
    tome(string, int, string, string*); // class constructor: receive number of arguments and then instantiate all of the class variable: tomeSize -> number of spells in initialList variable.
    ~tome(); //deconstructor (default deconstructor)
    int getTomeSize() const; //Returns the number of spells stored in the tome
    string getSpell(int) const; //accepts an array index and returns the spell stored at the index
    string getName() const; //This returns the name of the tome
    string getAuthor() const; //Returns the name of the author(s) of the tome
    friend ostream&  operator<<(ostream&, const tome&);//overload of the outstream operator: resulting operation must send to cout: 
    /*format is:
    Tome Name: Hexes and Incantations, A Study
    Author: S. Swaddles, D. Pines
    References: Hex Curse, Summon Ice Golem */

    tome operator+(const string&);//operator will enable a tome to add a spell that is given as a string into itself: If the tome is full, nothing should happen: if the tome is not full, then the new spell should be added at the first empty space.

    tome operator-(const string&);//operator will enable a tome to remove a spell that is provided as a string using the -operator:  first instance, from index 0, of the spell should be removed from the given tome: If the spell is not found, then nothing should happen to the tome.

    tome& operator=(const tome&);//an overload of the assignment operator: should be possible to assign an existing instance of a tome to a new instance: All of the variables of the old tome should be instantiated in the current tome

    bool operator>(const tome&); //compares two tomes: One tome is greater than the other: if one tome has more spells than the other: returns false if they are equal.

    bool operator<(const tome&); //compares two tomes: One tome is lesser than the other: if one tome has fewer spells than the other: return false if they are equal.

    bool operator==(const tome&);//an overload of the equality operator: should return true if two tomes are equal and false otherwise: Two tomes are only equal if they hold the same number of spells and have the same number of spells in the same exact quantities.
};

#endif
