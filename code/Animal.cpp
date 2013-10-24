#include<iostream>
#include<string>
#include<fstream>
#include"animal.h"


using namespace std;

Animal::Animal()
{
}
Animal::Animal(string pName, string pType, 
		      string pWeight, string pAge, 
			  string pAdjective)
{
	name=pName;
	type=pType;
	weight=pWeight;
	age=pAge;
	adjective=pAdjective;
}

void Animal::Display()const
{
	
	cout<<name<<" "<<type<<" "<<weight<<" "<<age<<" "<<adjective<<" "<<endl;
}

Animal::~Animal()
{cout<<"ANIMAL"<<endl;}