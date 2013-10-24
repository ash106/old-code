#include<iostream>
#include<string>
#include<fstream>
#include"animal.h"

#ifndef MAMMAL_H
#define MAMMAL_H

#include <string>
using namespace std;

class Mammal: public Animal 
{
	public:
		Mammal();
		Mammal( string pName,string pType,string pWeight, string pAge,string pAdj, string pSnack);
		virtual ~Mammal();
		virtual void Display()const;
		

	protected:
		string snack; 
};

#endif
