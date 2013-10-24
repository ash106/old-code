/******************************************************************
* Name: Alex Howington (ash106)       
* 
* Course: CSE 2813                   Date Due: Oct. 17
*
* File name: sort.cpp
*
* Program Description:
* This program sorts eight different files with varying order and 
* numbers of elements by using bubble and insertion sort on identical 
* arrays read from the file. The program then writes the sorted arrays
* along with the number of steps used to sort the array to 16 separate
* files.
*******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

//Function declarations
int bubbleSort(int array[], int size);
int insertionSort(int array[], int size);

int main()
{
	//Variable declarations
	int bubbleCount, insertCount;
	string t;
	string num; 
		
	//Gets data from Num8.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile("Num8.txt");
		
	//Initializes size to -1
	int size = -1;
		
	//Finds number of lines in file
	while(getline(inputFile, t, '\n'))
		size++;
	
	inputFile.close();
	ifstream inputFile2("Num8.txt");

	//Dynamic arrays to hold integers from input file
	int *arrayPtr;
	int *arrayPtr2;

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	//Reads integers from file to arrays
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	//Calls functions to sort arrays and return number of steps
	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	//Writes bubble-sorted array and number of steps to file
	ofstream bubbleOut("BubbleNum8.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	//Writes insertion-sorted array and number of steps to file
	ofstream insertOut("InsertionNum8.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close(); 
	
		
	//Gets data from Num16.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile3("Num16.txt");
		
	size = -1;
		
	while(getline(inputFile3, t, '\n'))
		size++;
	
	inputFile3.close();
	inputFile2.open("Num16.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleNum16.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionNum16.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Num32.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile4("Num32.txt");
		
	size = -1;
		
	while(getline(inputFile4, t, '\n'))
		size++;
	
	inputFile4.close();
	inputFile2.open("Num32.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleNum32.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionNum32.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Num64.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile5("Num64.txt");
		
	size = -1;
		
	while(getline(inputFile5, t, '\n'))
		size++;
	
	inputFile5.close();
	inputFile2.open("Num64.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleNum64.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionNum64.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Num128.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile6("Num128.txt");
		
	size = -1;
		
	while(getline(inputFile6, t, '\n'))
		size++;
	
	inputFile6.close();
	inputFile2.open("Num128.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleNum128.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionNum128.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Order128.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile7("Order128.txt");
		
	size = -1;
		
	while(getline(inputFile7, t, '\n'))
		size++;
	
	inputFile7.close();
	inputFile2.open("Order128.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleOrder128.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionOrder128.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Inv128.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile8("Inv128.txt");
		
	size = -1;
		
	while(getline(inputFile8, t, '\n'))
		size++;
	
	inputFile8.close();
	inputFile2.open("Inv128.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleInv128.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionInv128.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	
	//Gets data from Num256.txt, sorts arrays, and writes data to corresponding files
	ifstream inputFile9("Num256.txt");
		
	size = -1;
		
	while(getline(inputFile9, t, '\n'))
		size++;
	
	inputFile9.close();
	inputFile2.open("Num256.txt");

	arrayPtr = new int[size];
	arrayPtr2 = new int[size];
	
	for(int i = 0; i < size; i++)
	{
		inputFile2 >> arrayPtr[i];
		arrayPtr2[i] = arrayPtr[i];
	}

	inputFile2.close();

	bubbleCount = bubbleSort(arrayPtr, size);
	insertCount = insertionSort(arrayPtr2, size);
			
	bubbleOut.open("BubbleNum256.txt");
	for(int i = 0; i < size; i++)
		bubbleOut << arrayPtr[i] << endl;
	bubbleOut << bubbleCount << endl;
	bubbleOut.close();

	insertOut.open("InsertionNum256.txt");
	for(int i = 0; i < size; i++)
		insertOut << arrayPtr2[i] << endl;
	insertOut << insertCount << endl;
	insertOut.close();

	delete [] arrayPtr;
	delete [] arrayPtr2;
	
	return 0;
}

//Function that uses bubble sort to sort integers in array
int bubbleSort(int array[], int size)
{
	//Counter for steps
	int count = 0;
	int temp;

	for(int i = 1; i < size; i++)
		for(int j = 0; j < size-i; j++)
		{
			//Counter increase
			count = count + 1;
			//Compares adjacent elements
			if(array[j] > array[j+1])
			{
				//Switches elements if necessary
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	
	return count;
}

//Function that uses insertion sort to sort integers in array
int insertionSort(int array[], int size)
{
	//Counter for steps
	int count = 0;
	int temp;

	for(int j = 1; j < size; j++)
	{
		int i = 0;
		//Compares element j and i
		while(array[j] > array[i])
		{
			//Counter increase
			count = count + 1;
			i = i + 1;
		}
		//Puts elements j and i in correct position relative to each other       
		temp = array[j];
		for(int k = 0; k < j-i; k++)
			array[j-k] = array[j-k-1];
		array[i] = temp;
	}

	return count;
}