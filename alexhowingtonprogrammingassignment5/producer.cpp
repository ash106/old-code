/*-----------------------------------------------------------------------------
  producer.cpp
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 24, 2008
 
  Contents: producer.cpp generates two random numbers (one an int, one a float)
  and stores them in a Message (m).  It then reads the current stack position,
  writes the message to the stack, and then updates the stack position.
  
-----------------------------------------------------------------------------*/


//Preprocessor directives
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "message.h"

using namespace std;

int main()
{
	//Variables	
	Message m;
	int stackPos;
	
	//Seed random number generator
	srand(time(0));
	
	//Set message contents to random int and random float
	m.in = rand()%100;
	m.fl = (rand()%10000)/100.0;

	//Get stack position from file
	fstream outFile;
	outFile.open("stack.bin", ios::in|ios::out|ios::binary|ios::ate);
	outFile.seekg(0L, ios::beg);
	outFile.read((char *) &stackPos, sizeof(int));

	//Print current stack position
	cout << "top of stack position before push: " << stackPos << endl;
	
	//Write message to file at current stack position
	outFile.seekp(sizeof(int), ios::beg);
    outFile.seekp(stackPos*sizeof(Message), ios::cur);
	outFile.write((char *) &m, sizeof(Message));
	cout << "wrote the following values: message.fl = " << fixed << setprecision(2) << m.fl << "; message.in = " << m.in << endl;
	
	//Increment stack position
	stackPos++;
	
	//Write new stack position to file
	outFile.seekp(0L, ios::beg);
	outFile.write((char *) &stackPos, sizeof(int));
	cout << "top of stack position after push: " << stackPos << endl;
	cout << endl << "---------------------" << endl;

	return 0;
}