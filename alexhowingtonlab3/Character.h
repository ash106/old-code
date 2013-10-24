/*-----------------------------------------------------------------------------
  Character.h
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 2, 2008
 
  Contents: Character.h contains the Character class which holds information
  read from a text file about each character.
  
-----------------------------------------------------------------------------*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

class Character{
	public:
		Character(int s = 0, int p = 0, int a = 0, int r = 0, int d = 0){
			charNum = s;
			priority = p; 
			arrivalTime = a; 
			requestTime = r; 			 
			departTime = d; };
		int charNum;
		int priority;
		int arrivalTime;
		int requestTime;
		int departTime;
		bool operator < (const Character &s) const;
		bool operator == (const Character &s) const;
};


bool Character::operator < (const Character &s) const {
	return (priority < s.priority);
}

bool Character::operator == (const Character &s) const {
	return (priority == s.priority);
}

#endif