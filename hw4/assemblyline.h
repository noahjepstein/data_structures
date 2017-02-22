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

#ifndef ASSEMBLYLINE_H
#define ASSEMBLYLINE_H

#include <iostream>
#include "package.h"
#include "queue.h"
using namespace std;


class AssemblyLine
{

public: 

    AssemblyLine(); //default constructor for assembly line

    AssemblyLine(double r, int line_num); //constructs a line w/ rate and line num

    ~AssemblyLine(); //destructor

    void process(Package p); //adds a package to the assembly queue
    
    void doWork(); //does work on the active package

    bool notDone(); //returns whether work is completed on all packages
    
    PackageNode* ship(int t); //ships completed package, labeling w/ time

    double getRate(); //returns the rate of the line

    double getSize(); //num packages on the line

    double getTotalUnits(); //total units of work on the line

private: 

    Queue* line; //the queue for the assembly

    int line_number; //the "index" of the line

    double rate; //number of units of work a line can do in a minute

    double unitsOnLine; //number of total units on the assembly line

};

#endif
