// pirate.h - header file for "pirate" object

#ifndef PIRATE_H
#define PIRATE_H

#include <iostream>
#include "hookbook.h"

using namespace std;

class Pirate
{
public: 

    Pirate();
  
    Pirate(int memID, string nm);
    
    string getName();
    
    int getID();
    
    int getNumFriends();
    
    bool addFriend(int memID);
  
private:    
    
    int memberID;
    
    string name;
    
    int* friendList;
    
    int friendCount;
    
    int friendCapacity;
    
    bool expand();
};

#endif