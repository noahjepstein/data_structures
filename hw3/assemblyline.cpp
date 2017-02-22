//-----------------------------------------------------------------------------
// Filename: assemblyline.h
// Author:   Noah J. Epstein
// Date:     10/20/2013
// Rev-Date: 10/22/2013
//
// Description: Interface for an assembly line. It has a queue for arrived 
//              packages, and keeps track of the number of workers on the line
//              as well as the working rates. 
//              Provides interfaces for adding workers, shipping complete 
//              packages, checking if you've finished all packages, doing work,
//              and putting packages into the list. 
//
// Agknowledgements: Stack overflooooooow. 
//-----------------------------------------------------------------------------

#include "assemblyline.h"

//default constructor for assembly line creates a queue w/ 0 workers
AssemblyLine::AssemblyLine()
{
    line = new Queue;
    nWorkers = 0; 
}


//destructor
AssemblyLine::~AssemblyLine()
{
    delete line;
}


//overloaded constructer for assembly lines does the same as default
//except that it has workers already on the line
AssemblyLine::AssemblyLine(int workers, double* rates)
{
    line = new Queue;
    WorkerList = new double;
    nWorkers = workers;

    //sums the rate to get a total rate. 
    for (int i = 0; i < nWorkers; i++){
        WorkerList[i] = rates[i];
        totalRate += WorkerList[i];
    }
}


//adds a package to the queue. (pushes it onto the line). 
void AssemblyLine::process(Package new_p)
{
    PackageNode* p = new PackageNode;
    p->data = new_p;
    line->push(p);
}


//does work on the active package by subtracting the work rate from
//its units of work. 
void AssemblyLine::doWork()
{
    if (!line->isEmpty()) {
        line->decrementWork(totalRate);
    }
}

//if size is greater than zero, we still got some packages to process!
bool AssemblyLine::notDone()
{
    return (line->getSize() > 0);
}


//ships the package by popping it from the list and marking it w/ 
//departure time t. returns the package (so you can ship it). 
PackageNode* AssemblyLine::ship(int t)
{
    //check emptiness first because you can't get the front of empty list
    //zero or lesser work means you've fininshed assembling the package
    if (!line->isEmpty() && line->getFront().unitsRemaining <= 0) {

        PackageNode* p = new PackageNode;
        //pops the complete package and assigns it to something we can return
        p->data = line->pop(); 
        p->data.departureTime = t;
        return p;

    } else {

        return NULL; //if nothing's ready yet, we ship NULL. 
    }
}


//function for adding workers within the factory or from main, instead of
//passing the array of workers as an argument. 
void AssemblyLine::addWorker(double rate)
{
    totalRate += rate; 
}
