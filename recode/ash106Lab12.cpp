/**********************************************************************************************************
*	First Drive: Barry Segars		Date Assigned: 4/18/07
*	First Navigator:Alex Howington 	Date Due: 4/15/07
*
*	File Name: bss33Lab12.cpp
*
*	Program Description: Protected password
*	 
*	
**********************************************************************************************************/

#include<iostream>  //Preprocessor directives
#include<cstdlib>
#include<string>
#include<ctype.h>
#include<fstream>
#include"Password.h"

using namespace std;

#define SIZE 20

int main()
{
	char selection;
	int pass;
	int fileSize;
	string fileName;
	Password object;
	string line;
	string password;
	string filePassword;
	char fileName2[SIZE];

	cout<<"Welcome to Password Protected Text Documents"<<endl<<"-- your introduction to the process of protecting your documents"<<endl<<endl;
	cout<<"1.  Create a password protected document"<<endl<<"2.  Read a password protected document"<<endl<<endl;
	cout<<"Selection <1/2>:  ";
	cin>>selection;
	while (selection!='1' && selection!='2')
	{
		cout<<"You must enter either a 1 or a 2. Please re-enter your selection:  ";
		cin>>selection;
	}

	if(selection == '1')
	{
		cout << "Please enter the name of the document that you wish to create:  ";
		cin >> fileName;

		fileSize = fileName.length();
		
		for(int count = 0; count<fileSize; count++)
		{
			fileName2[count] = fileName.at(count);
		}
		
		ofstream outFile(fileName2);

		cout << "Enter password: ";
		cin >> password;
		
		pass = object.check(password);

		while(pass == 0)
		{
			cout << "Enter new password: ";
			cin >> password;
			pass = object.check(password);
		}
		
		outFile << password << endl << endl;

		cout << "Type the document.  To quit, use the same command as the vi editor" << endl;
		cout << "On a line by itself type" << endl << ":wq" << endl << endl;

		while(line != ":wq")
		{
			cin >> line;
			if(line != ":wq")
                outFile << line << endl;
		}
	}

	if(selection == '2')
	{
		cout << "Enter the name of the file that you wish to view:  ";
		cin >> fileName;
		
		fileSize = fileName.length();
		
		for(int count = 0; count<fileSize; count++)
		{
			fileName2[count] = fileName.at(count);
		}

		ifstream inFile(fileName2);
        
		while(inFile.fail())
		{
			cout << "That file name is invalid.  Please re-enter:  ";
			cin >> fileName;

			fileSize = fileName.length();
		
			for(int count = 0; count<fileSize; count++)
			{
				fileName2[count] = fileName.at(count);
			}

			ifstream inFile2 (fileName2);
		}
		
		getline(inFile, filePassword);

		cout << filePassword << endl;

		cout << "Enter the password to view the file:  ";
		cin >> password;

		pass = object.compare(password, filePassword);

		while(pass == 0)
		{
			cout << "The password is invalid.  Please re-enter password:  ";
			cin >> password;
			pass = object.compare(password, filePassword);
		}

		while(line != "EOF")
		{
			getline(inFile, line);
			cout << line << endl;
		}
	}

	return 0;
}
