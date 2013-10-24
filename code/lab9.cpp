#include<iostream>
#include<fstream>
#include<string>
#include"animal.h"
#include "mammal.h"
#include "bird.h"

using namespace std;

int main()
{
	ifstream inFile;
	inFile.open("animals.txt");
	Animal *beast;
	int size=0;
	char c[80];
	string aType,extra,name,type,weight,age,adjective, aT;
	aT="MAMMAL";

	while(inFile)
	{
		inFile.getline(c, '/n');
		size++;
	}
	
	inFile.clear();
	inFile.seekg(0L, ios::beg);

	//beast= new Animal[size-1];

	for(int i=1; i<size;i++)
	{
		inFile>>aType>>name>>type>>weight>>age>>adjective>>extra;

		if(aType==aT)
		{
			Mammal one(name, type, weight, age, adjective, extra);
			one.Display();
			
		}
		else 
		{
			Bird two(name, type, weight, age, adjective, extra);
			two.Display();
			
		}
		cout<<endl<<endl;
	}


}