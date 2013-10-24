/*-----------------------------------------------------------------------------
  consumer.cpp
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 24, 2008
 
  Contents: consumer.cpp gets the current stack position from the file, reads
  the message above the current stack position, and decreases the stack position
  by one.
  
-----------------------------------------------------------------------------*/


//Preprocessor directives
#include <iostream>
#include <fstream>
#include <iomanip>
#include "message.h"

using namespace std;

int main()
{
	//Variables
	int stackPos;
	Message m;
	
	//Get current stack position from file
	fstream inFile("stack.bin", ios::in|ios::out|ios::binary|ios::ate);
	inFile.seekg(0L, ios::beg);
	inFile.read((char *) &stackPos, sizeof(int));
	
	//If stack is empty, print message and exit program
	if(stackPos == 0)
	{
		cout << "stack is empty." << endl;
		exit(1);
	}

	//Print current stack position
	cout << "top of stack position before pop: " << stackPos << endl;
	
	//Decrement stack position
	stackPos--;
	
	//Read message from current stack position
	inFile.seekg(sizeof(int), ios::beg);
	inFile.seekg(stackPos*sizeof(Message), ios::cur);
	inFile.read((char *) &m, sizeof(Message));
	cout << "read the following values: message.fl = " << fixed << setprecision(2) << m.fl << "; message.in = " << m.in << endl;
	
	//Write new stack position to file
	inFile.seekp(0L, ios::beg);
	inFile.write((char *) &stackPos, sizeof(int));
	cout << "top of stack position after pop: " << stackPos << endl;
	cout << endl << "---------------------" << endl;

	return 0;
}
