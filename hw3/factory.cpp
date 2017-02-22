//-----------------------------------------------------------------------------
// Filename: factory.cpp
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

#include "factory.h"


const int INIT_N_LINES = 1;
const int WORDS_PER_PACKAGE_INPUT = 11;

//constructor initializes queues and sets timer to zero
Factory::Factory()
{
    prebuffer = new Queue;
    postbuffer = new Queue;
    t = 0;
}



//reads in data to the prebuffer
//puts the packages into the assembly line when they "arrive"
//prints the postbuffer of assembled packages
int Factory::run(int num_workers, double* rates)
{
    nWorkers = num_workers;
    wList = rates;

    readData();        //read in the packages from file
    //testprint(); //test prebuffer
    processPackages(); //run the assembly simulator
    print();           //output the list of assembled packages

    delete prebuffer;  //done with em
    delete postbuffer; //done with em

    //if time is zero after running, we didn't undergo the simulation
    //and the program failed. t == 0 returns 1, t > 0 returns 0
    return (!(t > 0));
}



//reads in data from file. it fills the array of strings "pdata" until 
//it holds 11 elements (the number of separate words in package input). 
//when it holds 11 elements, it sends that data to makePackage(), which 
//turns the array of strings into the appropriate "package-friendly" 
//data types. 
void Factory::readData()
{
    string pdata[WORDS_PER_PACKAGE_INPUT]; //holds one "line" of package input
    int i = 0;

    while (cin >> pdata[i]) {

        if (i == 10){
            makePackage(pdata); //turn the input into package data & buffer it
            i = 0; //put the counter back to zero to enter a new package
        } else {
            i++;
        }
    }
}



//turns an array holding string data from input into
//a package w/ ints, strings, and doubles. turns strings into 
//ints using atoi and c_str(). puts nUnits in unitsRemaining, 
//which creates a unitsRemaining double upon which we can do work.
void Factory::makePackage(string pdata[])
{
    PackageNode* p = new PackageNode; //new package

    p->data.orderID = pdata[3]; //3rd in he package string
    p->data.nUnits = atoi(pdata[5].c_str()); //turns string into int 
    p->data.unitsRemaining = p->data.nUnits; 
    p->data.arrivalTime = atoi(pdata[10].c_str()); //string to int

    prebuffer->push(p); //put it into the prebuffer
}



//test function that's not involved in the public operation of the 
//factory class. prints a single package on one line.
void Factory::printsingle(PackageNode* p)
{
    cout << "ID: " << p->data.orderID << " nUnits: " << p->data.nUnits; 
    cout << " unitsRemaining: " << p->data.unitsRemaining; 
    cout << " arrivalTime: " << p->data.arrivalTime << endl;
}



//this function is where all the magic happens!!
//it makes an assembly line with nWorkers and rates. 
//for the while conditional: until you empty your prebuffer into the 
//assembly line, isEmpty will trigger the conditional. once you empty the
//prebuffer, you'll still need to continue doing work - in fact, you do work
//while you're not done.
//at a single minute in time, you do work, ship any finished packages, and 
//process any packages that have arrived.
//all the while keeping track of time...very important in a busy factory. 
void Factory::processPackages()
{
    aLine = new AssemblyLine(nWorkers, wList);

    while (!prebuffer->isEmpty() || aLine->notDone()) { 
        
        aLine->doWork(); //does work on the packages in the line
        
        //ships complete packages and puts them in the post buffer
        postbuffer->push( aLine->ship(t) );

        //first, you can't check the time on an empty prebuffer. 
        //checking that is a safeguard against calling getFront on an 
        //empty buffer.
        //if the package's arrival time has come, process the package
        if (!prebuffer->isEmpty() && t >= prebuffer->getFront().arrivalTime) {
            aLine->process(prebuffer->pop());
        }
        t++; //the daily grind of factory life continues
    }
    delete aLine; //you've assembled everything at this point
}




//print function that goes through the postbuffer after completion of all
//data processing. uses a for loop and the size of the post queue to parse. 
//since it pops all elements before printing them, it also acts as a
//destructor. after printing, the queue is empty. 
void Factory::print()
{
    Package toPrint;
    int size = postbuffer->getSize();

    //if we called getSize every time, the size would decrease from popping
    for (int i = 0; i < size; i++) {
        
        toPrint = postbuffer->pop();

        cout << "Package order number "
        << toPrint.orderID 
        << " with " 
        << toPrint.nUnits
        << " units arrived at time "
        << toPrint.arrivalTime
        << " and left at time " 
        << toPrint.departureTime
        << endl;
    }
}



//test print function that only prints the prebuffer. not 
//involved in the public operation of the factory. deletes prebuffer.
void Factory::testprint()
{
    Package toPrint;
    int size = prebuffer->getSize();

    for (int i = 0; i < size; i++) {
        toPrint = prebuffer->pop();

        cout << "TEST Package order number "
        << toPrint.orderID 
        << " with " 
        << toPrint.nUnits
        << " units arrived at time "
        << toPrint.arrivalTime
        << " and left at time " 
        << toPrint.departureTime
        << endl;
    }
}
