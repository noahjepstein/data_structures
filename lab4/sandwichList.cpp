/* sandwichList.cpp
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */

#include "sandwichList.h"


SandwichList::SandwichList()
{
	capacity = INITIAL_SIZE;
	orders = new Order[INITIAL_SIZE];

	back = 0;
	front = 0;
}

bool SandwichList::isEmpty()
{
	if (size() == 0)
		return true;
	else
		return false;
}


int SandwichList::size()
{
	return (back - front + capacity) % capacity;
}

//function to pop
Order SandwichList::getNext()
{
    Order next;
    
    if (isEmpty()) {
      cout << "exit" << endl;
      exit(1);
    } 
    next = orders[front];
    front = (front + 1) % capacity; 

    return next;
}

//add an element, make sure it is not full, if it is call expand funciton
void SandwichList::add(const Order& sw)
{    
    orders[back] = sw;
    back = (back + 1) % capacity;  	
    
    if (front == back){
      expandList();
    }
}

//Double the queue size, copy the values, and reset back and front
void SandwichList::expandList()
{
    Order* temp = new Order[capacity * 2];
    
    for (int i = 0; i < capacity; i++){
	temp[i] = orders[(front + i) % capacity]; 
    }
    
    front = 0; 
    back = capacity;
    capacity *= 2;
    
    delete [] orders;
    orders = temp; 
}

void SandwichList::printOrder(Order s)
{
	cout << s.sandwich << " " << s.customerName 
	     << " " << s.orderNbr << " " << s.fries;
	cout << endl;
}



