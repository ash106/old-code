/*-----------------------------------------------------------------------------
  PriorityQueue.h
 
  Author: Alex Howington
  Class: CSE 1384
  Date: April 2, 2008
 
  Contents: PriorityQueue.h contains the Priority Queue data structure, which
  is based on a heap stored in a vector.  The file contains the function
  definitions to all of the Priority Queue functions.
  
-----------------------------------------------------------------------------*/

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <functional>

using namespace std;

//Priority queue based on a heap stored in a vector
template <typename Item_Type, typename Container = std::vector<Item_Type>>
class PriorityQueue{
	public:
		//Construct an empty priority queue
		PriorityQueue(){ isHeap = true; currentSize = 0; };
		//Insert an item into the priority queue
		void push(const Item_Type& item);
		//Remove the smallest item
		void pop();
		//Return true if the priority queue is empty
		bool empty();
		//Return the number of items in the priority queue
		int size();
		//Return a reference to the smallest item
		const Item_Type& top();
		//Sorts the heap if the heap is not in order
		void heapify();
	private:
		//The vector to hold the data
		Container data;
		bool isHeap;
		int currentSize;

		//Used by heapify() to sort the heap
		void percolateDown(int node);
		void percolateUp(int node);
      
    };

// Implemention of member functions
template<typename Item_Type, typename Container>
void PriorityQueue<Item_Type, Container>::push(const Item_Type& item) 
{
	data.resize(++currentSize + 1, item);
	if(isHeap)
		percolateUp(currentSize);
}

template<typename Item_Type, typename Container>
void PriorityQueue<Item_Type, Container>::pop() 
{
	if(!isHeap)
		heapify();
	data[1] = data[currentSize];
	data.resize(--currentSize + 1);
	percolateDown(1);
}

template<typename Item_Type, typename Container>
bool PriorityQueue<Item_Type, Container>::empty()
{
	return (currentSize == 0);
}

template<typename Item_Type, typename Container>
int PriorityQueue<Item_Type, Container>::size()
{
	return currentSize;
}

template<typename Item_Type, typename Container>
const Item_Type& PriorityQueue<Item_Type, Container>::top()
{
	if(!isHeap)
		heapify();
	return data[1];
}

template<typename Item_Type, typename Container>
void PriorityQueue<Item_Type, Container>::heapify()
{
	for(int i = currentSize / 2; i > 0; --i)
		percolateDown(i);
}

template<typename Item_Type, typename Container>
void PriorityQueue<Item_Type, Container>::percolateDown(int node)
{
	int l = node * 2;
	int r = node * 2 + 1;
	int largest;
	
	if(l <= currentSize && data[l] < data[node])
		largest = l;
	else 
		largest = node;
	
	if(r <= currentSize && data[r] < data[largest])
		largest = r;
		
	if(largest != node) 
	{
		Item_Type temp = data[largest];
		data[largest] = data[node];
		data[node] = temp;
		percolateDown(largest);
	}
}

template<typename Item_Type, typename Container>
void PriorityQueue<Item_Type, Container>::percolateUp(int node)
{
	int parent = node / 2;
	if (parent > 0 && data[node] < data[parent]) 
	{
		Item_Type temp = data[parent];
		data[parent] = data[node];
		data[node] = temp;
		percolateUp(parent);
	}
}
#endif
