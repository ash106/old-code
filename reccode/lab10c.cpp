/**************************************************************************
* First Driver: Brandon Gray                      Date Assigned:14 Nov 07
* First Navigator: Alex Howington                 Date Due:     28 Nov 07
*
* File Name: lab10c.cpp
*
* Program Discription: This file demonstrates exception handling
***************************************************************************/
#include<iostream>
#include "InvalidParameter.h"
using namespace std;

int computeAge(int birthYear, int currentYear);

int main()
{
	
	int year, age;//Variables used to current age and birth year

	//Getting user input
	cout << "Enter your birth year: ";
	cin >> year;

	//Try will check for valid birth year
	try{
	    age = computeAge(year, 2007);//Calls age computing function
	   }

	//will catch throw from compute age function and handle the exception
	catch(InvalidParameter)//computeAge will throw an InvalidParameter object
	{
		cout << "The parameters are invalid." << endl;
		exit(1);
	}

	//If birth year is valid main continues
	cout << "Your age: " << age << endl;
	cout << "Finishing normally" << endl;
	return 0;
}


//compute age function
int computeAge(int birthYear, int currentYear)
{
	int a = currentYear - birthYear;//computing age

	//Throws InvalidParameter object if the computed age is less than zero
	if(a <= 0)
	{
		InvalidParameter f;//Creates InvalidParameter object to be thrown
		throw f;
	}

	return a;
}