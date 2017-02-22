//-----------------------------------------------------------------------------
// Filename: queue.h
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

#ifndef QUEUE_H
#define QUEUE_H

#include "package.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Queue
{

public:

    Queue(); //constructs empty queue

    bool isEmpty(); //tests if queue is empty

    Package getFront(); //returns the data of front queue member

    Package getBack(); //returns data of back queue member

    int getSize(); //returns size of list

    void push(PackageNode* p); //puts a new package on the queue

    Package pop(); //pops a package off the front of the queue

    void decrementWork(double amount); //subtracts from remainingWork

private: 

    Package multiPop(); //helper - pops from a queue of multiple items

    Package singlePop(); //helper - pops from a queue of a single item

    int size; //size of the queue

    PackageNode* front; //front (oldest) node of the queue

    PackageNode* back; //back (newest) node of the queue

};

#endif
