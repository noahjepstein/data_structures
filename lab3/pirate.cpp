// pirate.cpp - implementation of "pirate" class

#include "pirate.h"


Pirate::Pirate()
{
    memberID = -1; //flag for empty member 
    
    name = ""; //flag val
    
    friendlist = NULL; //flag val
    
    friendcount = -1; //flag val
    
    friendCapacity = -1; //flag val
}
    
    

Pirate::Pirate(int memID, string nm)
{
    memberID = memID;
    
    name = nm;
    
    friendList = new int[INIT_SIZE];
    
    friendCount = 0;
    
    friendCapacity = INIT_SIZE; 
}


bool Pirate::isEmpty()
{
  return memberID == -1;
}


string Pirate::getName()
{
  return name;
}


int Pirate::getID()
{
  return memberID;
}


int Pirate::getNumFriends()
{
  return friendCount
}


bool Pirate::expand()
{
    int* temp = new int[friendCapacity*2];
    if (temp == NULL) {
      return false;
    
    for (int i = 0; i < friendCount; i++){
	temp[i] = friendList[i];
    }
    
    delete [] friendList;
    friendList = temp;
    return true;
}
  
  
bool Pirate::addFriend(int memID)
{
    if (isEmpty) {
      return false;
    } 
    
    if (friendCount >= friendCapacity) {
      
      if (!expand()) { 
	return false;
      }
    }
    friendList[friendCount] = memID;
    friendCount++;
    return true;
}

    
    
      
      
  
  
  
  
  