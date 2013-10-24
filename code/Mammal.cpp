#include<iostream>
#include<string>
#include<fstream>
#include"mammal.h"

using namespace std;

Mammal::Mammal()
{}
Mammal::Mammal( string pName,string pType,string pWeight, string pAge,string pAdj, string pSnack)
{
	name=pName;
	type=pType;
	weight=pWeight;
	age=pAge;
	adjective=pAdj;
	snack=pSnack;
}

Mammal::~Mammal()
{
	cout<<"MAMMAL->";
}

void Mammal::Display()const
{
	cout<<name<<" is a "<<adjective<<" "<<type<<"."<<endl;
	cout<<"It weighs "<<weight<<" pounds."<<endl;
	cout<<name<<" is "<<age<<" years old."<<endl;
	cout<<name<<" loves to eat "<<snack<<"."<<endl;
}

