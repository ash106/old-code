/**************************************************************************
* First Driver: Brandon Gray                      Date Assigned:14 Nov 07
* First Navigator: Alex Howington                 Date Due:     28 Nov 07
*
* File Name: lab10b.cpp
*
* Program Discription: This file implements the point class template
***************************************************************************/
#include<iostream>
#include"point.h"
using namespace std;

int main()
{
	
	Point<int> a(1,1);//Initializes an integer point object
	Point<int> b(0,0);//Initializes an integer point object
	Point<float> c(6.5, 4.25);//Initializes a float point object
	Point<float> d(.5,-3.75);//Initializes a float point object
	
	cout << "a is a point ";
	a.print();//Prints point a object

	cout << "b is a point ";
	b.print();//Prints point b object

	//Prints the distance between point a and b
	cout<<"The distance between a and b is "<<a.distance(b.getPointX(),b.getPointY())<< endl << endl;

	cout<<"c is a point ";
	c.print();//Prints point c object

	cout<<"d is a point ";
	d.print();//Prints point d object

	//Prints the distance between c and d
	cout<<"The distance between c and d is "<<c.distance(d.getPointX(),d.getPointY())<< endl;

	return 0;
}
