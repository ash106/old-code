/**********************************************************************************************************
*	First Drive: Barry Segars		Date Assigned: 3/28/07
*	First Navigator:Alex Howington 	Date Due: 4/4/07
*
*	File Name: bss33Lab11.cpp
*
*	Program Description: Password Parsing
*	 
*	
**********************************************************************************************************/

#include<iostream>  //Preprocessor directives
#include<cstdlib>
#include<string>
#include<ctype.h>

using namespace std;

int main()
{
	string password;
	int length;
	int lengthPass;
	char number;
	int total = 0;
	int numberPass;
	char special;	
	int total2 = 0;
	int specialPass;

	cout<<"Please create a password."<<endl;
	cout<<"Password must contain at least 8 characters."<<endl;
	cout<<"Password must contain at least 3 numbers."<<endl;
	cout<<"Password should contain at least one special character (such as #, *, &, etc)."<<endl;
	while(lengthPass == 0 || numberPass == 0 || specialPass == 0)
	{
    	cout<<"Please enter password: ";
		cin>>password;
	
		length = password.length();
	
		if(length < 8)
			lengthPass = 0;
		else
			lengthPass = 1;

		for(int count = 0;count < length; count++)
		{
			number = password.at(count);
			if(number == '1' || number == '2' || number == '3' || number == '4' || number == '5' || number == '6' || number == '7' || number == '8' || number == '9' || number == '0')
				total += 1;
		}

		if(total < 3)
			numberPass = 0;
		else
			numberPass = 1;

		for(count = 0;count < length; count++)
		{
			special = password.at(count);
			if(ispunct(special))
				total2 += 1;
		}

		if(total2 < 1)
			specialPass = 0;
		else
			specialPass = 1;

	
		if(lengthPass == 0)
			cout << "Your password should be at least 8 characters long." << endl;
		if(numberPass == 0)
			cout << "Your password should contain at least 3 numbers." << endl;
		if(specialPass == 0)
			cout << "Your password should contain at least one special character." << endl;
	}

	cout << "Congratulations! You have entered a good password." << endl;



	return 0;
}
