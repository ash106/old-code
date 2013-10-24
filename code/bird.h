#include<iostream>
#include<string>
#include<fstream>

#include"animal.h"
#ifndef BIRD_H
#define BIRD_H

#include <string>
using namespace std;

class Bird: public Animal
{
	public:
		Bird( string pName,string pType,string pWeight, string pAge,string pAdj, string pFeather);
		virtual ~Bird();
		virtual void Display()const; 
	
	protected:
		string feather;
};

#endif
