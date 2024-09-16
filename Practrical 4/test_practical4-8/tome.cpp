#include "tome.h"
#include <iostream>
#include <cstring>
#include <string>


using namespace std;

//constructor (recieves number of arguments and instantiates them in class)
tome :: tome(string name, string author){
    this->tomeName = name;
    this->author = author;
    currSpells = 0;  
}

// class constructor: receive number of arguments and then instantiate all of the class variable: tomeSize -> number of spells in initialList variable.
tome :: tome(string name, int tomeSize, string author, string* initialList){
    this->tomeName = name;
    this->author = author;
    this->currSpells = tomeSize; 

    unsigned count = 0;
    while (count < tomeSize){
        references[count] = initialList[count];
        count++;
    }
     
} 
tome ::~tome(){} //deconstructor (desfault deconstructor)

//Returns the number of spells stored in the tome
int tome :: getTomeSize() const{
    return currSpells;
}

//accepts an array index and returns the spell stored at the index
string tome :: getSpell(int i) const{
	return references[i];
}

//This returns the name of the tome
string tome :: getName() const{
	return tomeName;
}

//Returns the name of the author(s) of the tome
string tome :: getAuthor() const{
	return author;
}

//overload of the outstream operator: resulting operation must send to cout: 
ostream& operator<<(ostream& output, const tome& t){
    output<<"Tome Name: "<<t.getName()<<endl;
	output<<"Author: "<<t.getAuthor()<<endl;
	output<<"References: ";

    unsigned comma_count = 0;

    for(int i = 0; i < 10; i++){
        if(t.references[i]!="")
            comma_count++;
    }

    unsigned point_count = 0;

	for(int i = 0; i < 10; i++)
        if(t.references[i] != ""){
            if(point_count < comma_count){
                if(point_count == (comma_count-1))
                    output << t.references[i];
                else
                    output << t.references[i]<<", ";

                point_count++;
            }
        } output << endl;

	return output;
}


//operator will enable a tome to add a spell that is given as a string into itself: If the tome is full, nothing should happen: if the tome is not full, then the new spell should be added at the first empty space.
tome tome :: operator+(const string& add){
    for (int i = 0; i < 10; i++){
        if (references[i] == ""){
            this->references[i] = add;
            this->currSpells++;
            break;
        }

    }  

    return *this;
}


//operator will enable a tome to remove a spell that is provided as a string using the -operator:  first instance, from index 0, of the spell should be removed from the given tome: If the spell is not found, then nothing should happen to the tome.
tome tome :: operator-(const string& sub){
    for (int i = 0; i < 10; i++){
       if (references[i] == sub){
            references[i] = "";
			currSpells--;
			break;
        } 
    }
    return *this;
}


//an overload of the assignment operator: should be possible to assign an existing instance of a tome to a new instance: All of the variables of the old tome should be instantiated in the current tome
tome& tome :: operator=(const tome& oldTome){
    this->tomeName = oldTome.tomeName;
	this->author = oldTome.author;
	this->currSpells = oldTome.currSpells;
	
    for(int i = 0; i < 10; i++)
		this->references[i] = oldTome.references[i];
    
	return *this;
}

//compares two tomes: One tome is greater than the other: if one tome has more spells than the other: returns false if they are equal.
bool tome :: operator>(const tome& t){
    if (currSpells == t.currSpells)
        return false;

    else if(currSpells > t.currSpells)
        return true;

    return false; 
 }

//compares two tomes: One tome is lesser than the other: if one tome has fewer spells than the other: return false if they are equal.
bool tome :: operator<(const tome& t){
    if (currSpells == t.currSpells)
        return false;

    else if(currSpells < t.currSpells)
        return true;

    return false;    
} 

//an overload of the equality operator: should return true if two tomes are equal and false otherwise: Two tomes are only equal if they hold the same number of spells and have the same number of spells in the same exact quantities.
bool tome :: operator==(const tome& t){
    bool status;

    if (this->currSpells != t.currSpells)
        status = false;
    
    else if(this->currSpells == t.currSpells){
        unsigned a = 0, b = 0;
        for(int i = 0; i < t.currSpells; i++){
            for (int j = 0; j < t.currSpells; j++){
                if (references[i] == t.references[j]){
                    a++;
                    b++;
                }   
            }
        }
        if (a == b)
            status = true;
    }

    else
        status = false;


    return status;
    
}
