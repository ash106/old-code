#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	char fileName[20]; 
	char temp[2];
	
	cout << "Enter a file name: ";
	cin >> fileName;

	int width = 0;
	int length = 0;
	int scale;
	
	ifstream inputFile(fileName);
	inputFile >> temp;
	inputFile >> width >> length;
	inputFile >> scale;
	//cout << width << length << endl;

	int sizeOfArray = (width * length);

	int *array1 = 0;
	int *array2 = 0;
	int *array3 = 0;

	array1 = new int[sizeOfArray];
	array2 = new int[sizeOfArray];
	array3 = new int[sizeOfArray];

	for(int count1 = 0; count1 < sizeOfArray; count1++)
	{
		inputFile >> array1[count1];
		inputFile >> array2[count1];
		inputFile >> array3[count1];
	}
	
	
	/*for(int count = 0; count < sizeOfArray; count++)
	{
		cout << array1[count] << " ";
		cout << array2[count] << " ";
		cout << array3[count] << endl;
	}*/

	ofstream outFile("output.pgm");
	outFile << "P2" << endl;
	outFile << width << " " << length << endl;
	outFile << scale << endl;
	for(int count3 = 0; count3 < sizeOfArray; count3++)
	{
		outFile << ((array1[count3]+array2[count3]+array3[count3])/3) << endl;
	}
	outFile.close();

	ofstream outFile2("output2.pgm");
	outFile2 << "P2" << endl;
	outFile2 << width << " " << length << endl;
	outFile2 << scale << endl;
	for(int count3 = 0; count3 < sizeOfArray; count3++)
	{
		int temp2 = ((array1[count3]*.3)+(array2[count3]*.59)+(array3[count3]*.11));
		//cout << ((array1[count3]*.3)+(array2[count3]*.59)+(array3[count3]*.11)) << endl;
		outFile2 << temp2 << endl;
	}
	outFile2.close();
	
	return 0;
}
