

#ifndef HOOKBOOK_H
#define  HOOKBOOK_H

#include <iostream>
#include "pirate.h"

using namespace std;

//kept small for tesing purposes
//used in both friend initialization
//and pirate initialization

const int INIT_CAPACITY = 5;

class HookBook{

  public:
    /* constructor */
    HookBook();

    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, the pirate starts with no friend*/
    
    bool addPirate(int member, string nm);


    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
    void print() const;

 

    //the function you will write
    bool addFriend(int mem, int friendID);
    
    /* destructor if you have time*/
    ~HookBook();
	
private:
 
    Pirate** hbook;
    int pirateCount;
    int currentCapacity;
    bool expandPirates();
 
};

#endif
