//-----------------------------------------------------------------------------
// Filename: assemblyline.h
// Author:   Noah J. Epstein
// Date:     10/20/2013
// Rev-Date: 11/11/2013
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
    rate = -1; //flag for non-initialized rate
}


//destructor
AssemblyLine::~AssemblyLine()
{
    delete line;
}


//overloaded constructer for assembly lines does the same as default
//except that it has workers already on the line
AssemblyLine::AssemblyLine(double r, int line_num)
{
    line = new Queue;
    rate = r;
    line_number = line_num;
}


//adds a package to the queue. (pushes it onto the line). 
void AssemblyLine::process(Package new_p)
{
    PackageNode* p = new PackageNode;
    p->data = new_p;
    p->data.line = line_number;
    line->push(p);
    unitsOnLine += p->data.nUnits;
}


//does work on the active package by subtracting the work rate from
//its units of work. keeps track of the number of units currently on the
//assembly line
void AssemblyLine::doWork()
{
    if (!line->isEmpty()) {

        double rem = line->getFront().unitsRemaining;
        //if we do work when there's more work remaining than the line's rate,
        //then we do a "rate" amount of work. if the rate is greater than the 
        //remaining amount of work, we only do the amount of work 
        //that remains in the package. KINDA HACKY. But effective.
        unitsOnLine -= rate - (rate > rem)*(rate - rem);

        line->decrementWork(rate);                    
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


//func to get the rate of a line
double AssemblyLine::getRate()
{
    return rate;
}


//function to get the number of packages on a line
double AssemblyLine::getSize()
{
    return line->getSize();
}


//function to get the number of units on the line
double AssemblyLine::getTotalUnits()
{
    return unitsOnLine;
}

