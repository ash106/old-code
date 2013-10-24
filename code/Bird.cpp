#include<iostream>
#include<string>
#include<fstream>
#include"bird.h"
using namespace std;

Bird::Bird( string pName,string pType,string pWeight, string pAge,string pAdj, string pFeather)
{
	name=pName;
	type=pType;
	weight=pWeight;
	age=pAge;
	adjective=pAdj;
	feather=pFeather;
}

Bird::~Bird()
{
  cout<<"BIRD->";
}
void Bird::Display()const
{
	cout<<name<<" is a "<<adjective<<" "<<type<<"."<<endl;
	
	cout<<"It weighs "<<weight<<" pounds."<<endl;
	cout<<name<<" is "<<age<<" years old."<<endl;
	cout<<name<<"'s feathers are "<<feather<<"."<<endl;
}
	