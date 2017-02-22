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

    AssemblyLine(int nWorkers, double* wList);

    ~AssemblyLine(); //destructor

    void process(Package p); //adds a package to the assembly queue
    
    void doWork(); //does work on the active package

    bool notDone(); //returns whether work is completed on all packages
    
    PackageNode* ship(int t); //ships completed package, labeling w/ time

    void addWorker(double rate); //when you add a worker, you add their rate

private: 

    Queue* line; //the queue for the assembly

    int nWorkers; //number of workers on the assembly line

    //dynamic list of rates, becuase the only thing a worker has is a rate
    double* WorkerList;

    //total rate represents the total working rate of all workers. All workers
    //on a line work on a single package simultaneously, so the actual working
    //rate is the sum of the individual working rates.
    double totalRate; 

};

#endif
