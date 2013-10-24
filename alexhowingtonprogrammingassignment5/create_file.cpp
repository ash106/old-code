/*-----------------------------------------------------------------------------
  create_file.cpp
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 24, 2008
 
  Contents: create_file.cpp creates a file called "stack.bin" and stores the
  integer 0 in binary form.
  
-----------------------------------------------------------------------------*/


//Preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Variables
	int stackPos = 0;
	int values[10];
	
	//Seed random number generator
	srand(time(0));

	//Create file in binary mode
	ofstream outFile;
	outFile.open("stack.bin", ios::out|ios::binary);

	//Write first stack position to file
	outFile.write((char *) &stackPos, sizeof(int));

	//Get 10 random numbers which are 0 or 1
	for(int i = 0; i < 10; i++)
		values[i] = rand()%2;
	
	//Print random numbers to screen
	cout << "random values: " << endl;
	for(int i = 0; i < 10; i++)
		cout << values[i] << " ";
	cout << endl << "---------------------" << endl;

	return 0;
}