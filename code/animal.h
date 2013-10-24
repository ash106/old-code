#include<iostream>
#include<string>
#include<fstream>


#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
public:
	Animal();
	Animal(string pName, string pType, 
		      string pWeight, string pAge, 
			  string pAdjective);
	virtual void Display()const;
	virtual ~Animal();
protected:
	string name, type, weight, age, adjective;
	
};

#endif
