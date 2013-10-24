/*-----------------------------------------------------------------------------
  print_file.cpp
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 24, 2008
 
  Contents: print_file.cpp prints the contents of the file. Even if the current
  stack position is smaller than the number of messages in the file, print_file
  prints out all messages stored in the file.
  
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
	int messNum = 0;

	
	//Get current stack position
	ifstream inFile;
	inFile.open("stack.bin", ios::in|ios::binary);
	inFile.read((char *) &stackPos, sizeof(int));

	//Print contents of file
	cout << "Contents of the file: " << endl;
	cout << "Top of stack position is: " << stackPos << endl;
	//Print each message until the file is empty
	while(inFile.read((char *) &m, sizeof(Message)))
	{
		cout << "Message " << messNum << ":  fl= " << fixed << setprecision(2) << m.fl << "; in = " << m.in << endl;
		messNum++;
	}
	cout << endl << "---------------------" << endl;

	return 0;
}