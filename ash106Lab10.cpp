/**********************************************************************************************************
*	First Drive: Barry Segars		Date Assigned: 3/28/07
*	First Navigator: 				Date Due: 4/4/07
*
*	File Name: bss33Lab9.cpp
*
*	Program Description: Driver's Test 
*	 
*	
**********************************************************************************************************/

#include<iostream>  //Preprocessor directives
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

#define SIZE 1000
void fillArrays(string maleNames[], int maleRank[], string femaleNames[], int femaleRank[], ifstream &inFile);
void sortArrays(string names[], int rank[]);
int searchArrays(string names[], int rank[], string key);

int main()
{
	ifstream inFile;
	string maleNames[SIZE];
	string femaleNames[SIZE];
	int maleRank[SIZE];
	int femaleRank[SIZE];
	int selection;
	string key;
	string gender;
	char again = 'y';
	int rank;
	
	cout<<"Welcome to Baby Names:  the database for decades!"<<endl<<endl;
	cout<<" 1.  1900"<<endl<<" 2.  1910"<<endl<<" 3.  1920"<<endl<<" 4.  1930"<<endl<<" 5.  1940"<<endl<<" 6.  1950"<<endl<<" 7.  1960"<<endl<<" 8.  1970"<<endl<<" 9.  1980"<<endl<<"10.  1990"<<endl;
	cout<<endl<<"Enter you selection:  ";
	cin>>selection;

	while(selection != 1 && selection != 2 && selection !=3 && selection !=4 && selection !=5 && selection !=6 && selection !=7 && selection !=8 && selection !=9 && selection !=10)
	{
		cout << "Invalid selection. Please enter your selection:  ";
		cin >> selection;
	}
	
	if(selection == 1)
		inFile.open("NamesOf1900s.txt");
	if(selection == 2)
		inFile.open ("NamesOf1910s.txt");
	if(selection == 3)
		inFile.open ("NamesOf1920s.txt");
	if(selection == 4)
		inFile.open ("NamesOf1930s.txt");
	if(selection == 5)
		inFile.open ("NamesOf1940s.txt");
	if(selection == 6)
		inFile.open ("NamesOf1950s.txt");
	if(selection == 7)
		inFile.open ("NamesOf1960s.txt");
	if(selection == 8)
		inFile.open ("NamesOf1970s.txt");
	if(selection == 9)
		inFile.open ("NamesOf1980s.txt");
	if(selection == 10)
		inFile.open ("NamesOf1990s.txt");

	fillArrays(maleNames, maleRank, femaleNames, femaleRank, inFile);

	sortArrays(maleNames, maleRank);
	sortArrays(femaleNames, femaleRank);

	while(again == 'y' || again == 'Y')
	{
		cout << endl << "What name do you wish to search for?" << endl << "Enter name:  ";
		cin >> key;
		cout << endl << "What gender is this baby name?" << endl << "Enter male or female:  ";
		cin >> gender;

		if(gender != "Male" && gender != "male" && gender != "Female" && gender != "female")
		{
			cout << "Invalid selection. Please enter male or female:  ";
			cin >> gender;
		}

		if(gender == "Male" || gender == "male")
			rank = searchArrays(maleNames, maleRank, key);
		if(gender == "Female" || gender == "female")
			rank = searchArrays(femaleNames, femaleRank, key);

		if(rank != 0)
            cout << key << " has rank " << rank << " in this decade." << endl << endl;
		else
			cout << key << " was not ranked in the top 1000 names of this decade." << endl << endl;
		cout << "Do you wish to continue?(y/n)  ";
		cin >> again;
		while(again != 'y' && again != 'Y' && again != 'n' && again != 'N')
		{
			cout << "Invalid selection. Please enter y or n:  ";
			cin >> again;
		}
	}

	return 0;
}

void fillArrays(string maleNames[], int maleRank[], string femaleNames[], int femaleRank[], ifstream &inFile)
{
	
	string extraction;
	for(int count = 0;count<13;count++)
	{
		inFile >> extraction;
	}

	int rank;
	string name;
	string extraction2;
	for(count = 0;count<SIZE;count++)
	{
        inFile >> rank;
		maleRank[count] = rank;
		femaleRank[count] = rank;
		inFile >> name;
		maleNames[count] = name;
		inFile >> extraction2;
		inFile >> name;
		femaleNames[count] = name;
		inFile >> extraction2;
	}


	inFile.close();
}

void sortArrays(string names[], int rank[])
{
	int i, j, temp2;
	string temp;
	for(i = 0; i < SIZE-1; i++)
	{
		for(j = 0; j < SIZE-i-1; j++)
		{
			if(names[j] > names[j+1])
			{
				temp = names[j];
				names[j] = names[j+1];
				names[j+1] = temp;
				temp2 = rank[j];
				rank[j] = rank[j+1];
				rank[j+1] = temp2;
			}
		}
	}
}

int searchArrays(string names[], int rank[], string key)
{
	int first = 0, last = SIZE - 1, mid;
	mid = (first + last)/2;
	while(first <= last && key != names[mid])
	{
		if(key < names[mid])
			last = mid - 1;
		else
			first = mid + 1;
		mid = (first + last)/2;
	}
	if (key == names[mid])
		return rank[mid];
	else
		return 0;
}
	
