//-----------------------------------------------------------------------------
// Filename: factory.h
// Author:   Noah J. Epstein
// Date:     10/20/2013
// Rev-Date: 10/22/2013
//
// Description: Implementation file for the "factory" class. Has an assembly  
//              line, workers, etc. The factory has pre and post "buffers". 
//              The former stores packages from input that have not yet 
//              "arrived". The latter stores packages that have been 
//              "assembled". 
//
//              The factory runs a simulation by first reading in data, 
//              processing the packages (the part that actually takes "time"),
//              then printing all the "assembled" packages. It returns 0 
//              if the timer has run. 
//              
// 
// Agknowledgements: A ton of Stack Overflow. 
//-----------------------------------------------------------------------------

#ifndef FACTORY_H
#define FACTORY_H

#include "assemblyline.h"
#include "package.h"
#include "queue.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Factory
{

public:

    Factory(); //build a factory. make way for ducklings. 

    int run(int num_workers, double* rates); //runs the simulator

private: 

    void testprint(); //tests print function on prebuffer instead of postbuffer to check input

    void printsingle(PackageNode* p); 

    //int nAssemLines; //number of assem lines in factory ONLY ONE

    int nWorkers; //number of workers input from cmd line

    double* wList; //array of worker rates corresponding with nWorkers

    Queue* prebuffer; //holds pre-assembled packages

    Queue* postbuffer; //holds post-assembled packages
        
    void readData(); //reads in data from file  

    void makePackage(string pdata[]); //makes a package node from input

    void processPackages(); //func including the "timed" component of assembly

    void print(); //prints list of assembled packages

    AssemblyLine* aLine; //dynamically created assembly line

    int t; //counter for time

};

#endif
