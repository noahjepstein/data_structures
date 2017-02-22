//-----------------------------------------------------------------------------
// Filename: factory.h
// Author:   Noah J. Epstein
// Date:     10/20/2013
// Rev-Date: 11/11/2013
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

    Factory(); //build a factory. 

    Factory(int n_lines, double* rates); //constructs multiple lines w/ rates

    int run(); //runs the simulator

private: 

/////////////////////////////////DATA MEMBERS//////////////////////////////////   


    int nLines; //number of assem lines in factory ONLY ONE
    
    int t; //counter for time    

    int min; 
    
    double* rate_list; //array of rates corresponding w/ respective lines

    Queue* prebuffer; //holds pre-assembled packages

    Queue* postbuffer; //holds post-assembled packages

    AssemblyLine** aLine; //dynamically created assembly lines. 


//////////////////////////FUNCTIONS FOR LOADING PACKAGES///////////////////////
    

    void readData(); //reads in data from file  

    void makePackage(string pdata[]); //makes a package node from input


//////////////////////////FUNCS FOR PROCESSING PACKAGES////////////////////////


    void processPackages(); //func including the "timed" component of assembly

    bool stillWorking(); //determines if we need to keep doing work on packages

    void work(); //helps processPackages

    void ship_packages(); //ships packages from all lines

    void dispatch(); //moves packages from prebuffer to appropriate lines

    void print(); //prints list of assembled packages


////////////////////////////////////TEST FUNCTIONS/////////////////////////////


    //tests print function on prebuffer instead of postbuffer to check input
    void testprint(); 

    //prints a single package. to test output. 
    void printsingle(PackageNode* p); //just prints one package. for TESTS    


///////////////////////////////////////////////////////////////////////////////

};

#endif
