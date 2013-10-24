/*-----------------------------------------------------------------------------
  sim.cpp
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 2, 2008
 
  Contents: sim.cpp contains the main function which uses the Character.h
  and PriorityQueue.h to simulate characters entering and leaving a queue
  in front of a wizard's cave.  Depending on the input from the command line,
  the program uses a FIFO or Shortest Request First sort on a heap to determine
  which character enters the cave next.  The program then prints out the average
  wait time after all the characters have left the cave.  File also includes
  bonus for discrete event simulation.
  
-----------------------------------------------------------------------------*/


//Preprocessor directives
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "PriorityQueue.h"
#include "Character.h"

using namespace std;

//Pass sortType and fileName to main
int main(int argc, char *argv[]) 
{
	//Variables
	PriorityQueue<Character> queue;
	string sortType;
	string fileName;
	int arrival = -1;
	int request = -1;
	int cNum = 0;
	Character *next = NULL;
	Character *current = NULL;
	Character current2;
	int currentTime = 0;
	int time2 = 0;
	double wait = 0;
	
	//Get sortType and fileName from command line
	if(argv[1])
		sortType = argv[1];
	if(argv[2])
		fileName = argv[2];
	
	//Open file
	ifstream inFile;
	inFile.open(fileName.c_str());
	
	//Test for valid usage
	if((sortType != "fcfs" && sortType != "srf") || fileName == "") 
	{
		cout << endl << "Usage: sim [fcfs|srf] infile" << endl;
		//Close file if sortType is not valid
		if(inFile.is_open()) 
			inFile.close();
	} 
	//Test for valid input file
	else if(!inFile.is_open()) 
	{ 
		cout << endl << "Cannot open " << fileName << endl;
	} 
	else 
	{
		//Read first character from file
		inFile >> arrival >> request;
		//If valid, create next character
		if(arrival >= 0 && request >= 0) 
		{
			//Using fcfs sort
			if(sortType == "fcfs")
				next = new Character(cNum++, arrival, arrival, request);
			//Using srf sort
			else
				next = new Character(cNum++, request, arrival, request);
		}
		else 
		{
			next = NULL;
			//If arrival is valid but request is not, print error message
			if(arrival >= 0) 
			{ 
				cout << "Error in input file" << endl; 
				exit(1); 
			} 
		}
		
		//Print table headers
		cout << endl;
		cout << left << setw(13) << "Time" << "Event" << endl;
		cout << left << setw(13) << "----" << "-----" << endl;
		
		//For loop that increments time by 1 each loop
		for(currentTime = 0; next != NULL || !queue.empty() || current != NULL; currentTime++) 
		{
			//Check for arrival of next character and push onto heap
			if(next != NULL && currentTime == next->arrivalTime) 
			{ 
				cout << left << setw(13) << currentTime << "Character " << next->charNum << " enters the queue" << endl;
				queue.push(*next);
				delete next;
				arrival = -1;
				request = -1;
				//Get next character from file
				inFile >> arrival >> request;
				if(arrival >= 0 && request >= 0)
				{
					//Using fcfs sort
					if(sortType == "fcfs")
						next = new Character(cNum++, arrival, arrival, request);
					//Using srf sort
					else
						next = new Character(cNum++, request, arrival, request);
				}
				else 
				{
					next = NULL;
					//If arrival is valid but request is not, print error message
					if(arrival >= 0)
					{ 
						cout << "Error in file" << endl; 
						exit(1); 
					} 
				}
			}
			//If character is done, leave cave
			if(current != NULL && currentTime == current->departTime) 
			{ 
				cout << left << setw(13) << currentTime << "Character " << current->charNum << " leaves cave" << endl;
				//Calculate wait time for each character as they leave the cave
				wait += (current->departTime - current->requestTime) - current->arrivalTime; 
				delete current;
				current = 0;
			}
			//If cave is empty and queue is not empty, next character enters cave
			if(current == NULL && !queue.empty()) 
			{ 
				current2 = queue.top();
				current = &current2;
				queue.pop();
				current->departTime = currentTime + current->requestTime;
				cout << left << setw(13) << currentTime << "Character " << current->charNum << " enters the cave" << endl;
			}
			//BONUS
			//Calculate next event time and skip to event time - 1
			time2 = currentTime;
			if(next != NULL) 
				time2 = next->arrivalTime - 1;
			if(current != NULL && (next == NULL || current->departTime - 1 < time2)) 
				time2 = current->departTime - 1;
			currentTime = time2;
		}
		inFile.close();
		//Print end of simulation and average wait time
		cout << endl << "Simulation over..." << endl << endl;
		cout << "Average wait time: " << (wait / cNum) << endl;
	}
	
	return 0;
}



