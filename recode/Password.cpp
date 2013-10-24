#include<iostream>
#include<string>
#include"Password.h"

using namespace std;

//default or no-arg constructor
Password::Password()
{
	password = "  ";
}

int Password::check(string password)
{
	int length;
	int lengthPass = 0;
	char number;
	int total = 0;
	int numberPass = 0;
	char special;	
	int total2 = 0;
	int specialPass = 0;

	//Check length of password
	length = password.length();
	
	//Length pass or fail test
	if(length < 8)
		lengthPass = 0;
	else
		lengthPass = 1;

	//Check for numbers in password
	for(int count = 0;count < length; count++)
	{
		number = password.at(count);
		if(number == '1' || number == '2' || number == '3' || number == '4' || number == '5' || number == '6' || number == '7' || number == '8' || number == '9' || number == '0')
			total += 1;
	}

	//Number pass or fail test
	if(total < 3)
		numberPass = 0;
	else
		numberPass = 1;

	//Check for special characters
	for(count = 0;count < length; count++)
	{
		special = password.at(count);
		if(ispunct(special))
			total2 += 1;
	}

	//Special character pass or fail test
	if(total2 < 1)
		specialPass = 0;
	else
		specialPass = 1;

	
	//Tells user what is wrong with password
	if(lengthPass == 0 || numberPass == 0 || specialPass == 0)
		cout << "Your password must meet the following requirements:" << endl;
	if(lengthPass == 0)
		cout << "\tIt must be at least 8 characters long." << endl;
	if(numberPass == 0)
		cout << "\tIt must have at least 3 numbers." << endl;
	if(specialPass == 0)
		cout << "\tIt must have at least one special character (not a digit or letter)." << endl;

	if(lengthPass == 0 || numberPass == 0 || specialPass == 0)
		return 0;
	else
		return 1;
}
	
int Password::compare(string password, string filePassword)
{
	if(password == filePassword)
		return 1;
	else
		return 0;
}