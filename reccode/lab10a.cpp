/**************************************************************************
* First Driver: Brandon Gray                      Date Assigned:14 Nov 07
* First Navigator: Alex Howington                 Date Due:     28 Nov 07
*
* File Name: lab10a.cpp
*
* Program Discription: This file uses a function template
***************************************************************************/
#include<iostream>

using namespace std;

//template for absolute function
template <class T>
T absolute(T a)//returns template as type T
{
  if(a>=0)
	{
		return a;
	}
  else
	{
		a=a*(-1);
		return a;
	}
}
int main()
{
	int c;//interger to find absolute value of
	float b;//float to find absolute value of

	//Getting user value for c
	cout<<"Enter an integer to find its absolute value:  ";
	cin>>c;
	
	//Calling absolute value function and printing value
	cout<<"Absolute value of "<<c<<" = "<<absolute(c)<<endl;

	//Getting user value for b
	cout<<"Enter a float to find its absolute value:  ";
	cin>>b;
	
	//Calling absolute value function and printing value
	cout<<"Absolute value of "<<b<<" = "<<absolute(b)<<endl;


}


