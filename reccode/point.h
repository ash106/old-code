/**************************************************************************
* First Driver: Brandon Gray                      Date Assigned:14 Nov 07
* First Navigator: Alex Howington                 Date Due:     28 Nov 07
*
* File Name: point.h
*
* Program Discription: This file demonstrates a class template
***************************************************************************/
#include<cmath>
#include<iostream>

using namespace std;

#ifndef POINT_H
#define POINT_H

template <class t>
class Point
{
private:
	t x,y;
public:

	//Constructor
	Point(){x=y=0;}
	//Constructor with t type parameters
	Point(t a,t b)
	{
		x=a;
		y=b;
	}

	//Sets point's x value with t type parameter
	void setPointX(t a)
	{
		x=a;
	}

	//Sets point's y value with t type parameter
	void setPointY(t a)
	{
		y=a;
	}
	
	//Returns point's x value with t type 
	t getPointX()
	{
		return(x);
	}

	//Returns point's y value with t type 
	t getPointY()
	{
		return(y);
	}

	//Prints point
	void print()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}

	//Returns the distance between two points as a double
	double distance(t a, t b)
	{
		double dis;
		double sum;//used to calculate  value to send to square root function
		sum = (a-x)*(a-x)+(b-y)*(b-y);//calculating value to send to square root function
		dis=sqrt(sum);//calling square root function
		return(dis);
	}
};

#endif