//-----------------------------------------------------------------------------
// Filename: queue.cpp
// Author:   Noah J. Epstein
// Date:     10/20/2013
// Rev-Date: 10/22/2013
//
// Description: Implementation for a queue. Uses a doubly linked list.
//              Has a front and a back (you pop from the front, and push 
//              onto the back). You can get copies of the data at front and
//              back. You can push and pop. You can decrement work by a 
//              value you specify. 
//
// Agknowledgements: Stacks on stacks on stack overflow. 
//-----------------------------------------------------------------------------

#include "queue.h"

//constructs an empty queue. 
Queue::Queue()
{
    front = NULL;
    back  = NULL;
    size  = 0;
}


//returns true if there's nothing in our queue. 
bool Queue::isEmpty()
{
    return (front == NULL);
}


//returns the data at the front of the list.
//stops program if we try to get the back of an empty queue. 
Package Queue::getFront()
{
    if(isEmpty()){
        
        cerr << "Can't get front of empty queue" << endl;
        exit(1);
   
    } else {
        
        return front->data;
    }
}


//returns the data at the front of the queue. 
//stops program if we try to get the back of an empty queue. 
Package Queue::getBack()
{
    if(isEmpty()){

        cerr << "Can't get back of empty queue" << endl;
        exit(1);
    } else {

        return back->data;
    }
}


//returns private data member
int Queue::getSize()
{
    return size;
}


//when we call push, the data has already been put into p. we don't need to 
//"new" anything. program returns to caller if you try to push a null package.
void Queue::push(PackageNode* p)
{
    if (p == NULL) { //pushing a null package> nothing happens.
        return;

    } else if (isEmpty()) { //first package in line
    
        front = p; //first is the front and the back
        back  = p; 
        front->next = NULL; //with nothing next to it
        front->prev = NULL;
        size++;
    
    } else { //putting a package at the back of the queue
        
        p->next = back; 
        back->prev = p; 
        p->prev = NULL;
        back = p;
        size++;
    }
}


//removes the front of the queue, deletes its node, and returns its data.
//updates the front to be the package that entered the line subsequent to
//the one we popped. if we pop an empty list, we get a package with a flag
//value to tell us that it's empty. (for debugging purposes). 
Package Queue::pop()
{
    if (!isEmpty()) {
        if (size > 1) { //queue with multiple items
            return multiPop();
        
        } else {       //queue with single item
            return singlePop();
        }

    } else { //queue with 0 items
        
        Package toPop;
        toPop.nUnits = -1; //flag val for empty package
        size = 0;
        return toPop;
    }
}


//pops a package from the front of a multi-element queue. moves
//the "front" pointer to the element behind it and deletes the 
//original front node. sets the new front->next to NULL.
//incidentally, if you pop until the list is empty, pop has acted as 
//a destructor. 
Package Queue::multiPop()
{
    PackageNode* toDelete;

    Package toPop = front->data;
    toDelete = front;
    front = front->prev;
    delete toDelete;
    front->next = NULL;
    
    size--;
    return toPop;   
}


//pops a package from a single-item queue. returns the data, 
//deletes the node, and sets the front and back pointers to NULL.
//decrements size. effectively a destructor for the last item in a list. 
Package Queue::singlePop()
{
    Package toPop = front->data;
    delete front;
    front = NULL;
    back = NULL;
    
    size--;
    return toPop;
}




//function that decrements the remaining amount of work in a package
//by "amount". called every time you do work on a package. 
void Queue::decrementWork(double amount)
{
    front->data.unitsRemaining -= amount; 
}
