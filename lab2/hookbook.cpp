#include "hookbook.h"

HookBook::HookBook()
{
    hbook = new Pirate[INIT_CAPACITY];
    currentCapacity = INIT_CAPACITY;
    pirateCount = 0;
}


    /* Adds a new pirate to HookBook, probably the member should
       be created by the hookbook system, for now it is sent in
       from main, friends is a pointer to a dynamic array we
       copy it to the hookbook data structure, if it is null the pirate
       has no friend*/
    
bool HookBook::addPirate(int member, string nm)
{
    //check to see if we need to expand to add
    if(pirateCount >= currentCapacity)
    {
            // check to see if expand worked
            if(!expandPirates())
            {
                return false;
            }
    }
    //made it here so we can add a pirate
    hbook[pirateCount].memberID = member;
    hbook[pirateCount].name = nm;
    hbook[pirateCount].friendList = NULL;
    hbook[pirateCount].friendCount = 0;
    hbook[pirateCount].friendCapacity = 0;
    pirateCount++;
    return true;
    
    
}

    /* Prints the values in the list in ascending order. */
    /* This method is "const", which is a promise to the compiler
     that it won't change the value of any private variables. */
void HookBook::print() const
{
    cout << "There are " << pirateCount << " pirates in the system." << endl;
    for (int i = 0; i < pirateCount; i++) {
        cout << "Pirate: " << hbook[i].name << " with memberID: "
             << hbook[i].memberID << " has friends ";
        
        for(int j = 0; j < hbook[i].friendCount; j++)
        {
            cout << hbook[i].friendList[j] << " ";
        }
        
        cout << endl;
        
    }
}

    
 
//the function you will write you may have an empty list to start
bool HookBook::addFriend(int mem, int friendID)
{
  for (int i = 0; i < pirateCount; i++) {
     
     if(hbook[i].memberID == mem) {
	
	if (hbook[i].friendList == NULL) {
	    
	    hbook[i].friendList = new int[INIT_CAPACITY];
	    hbook[i].friendList[0] = friendID;
	    return true;
	
	} else {
	    
	    if (hbook[i].friendCapacity == hbook[i].friendCount) {
	     
	      if (!expand_friendList(i)) {
		    return false;
		
	      } else {
		   
		  hbook[i].friendList[ (hbook[i].friendCount) ] = friendID;
		    hbook[i].friendCount++;
		    return true;
	        }
	    }
        }
     }
  }
  return false;
}
    

bool HookBook::expand_friendList(int index)
{
  int* temp;
  temp = new int[hbook[index].friendCapacity * 2];
 
  if (temp == NULL) {
    return false; //failed to allocate enough mem to expand friendList
  }
  
  for (int i = 0; i < hbook[index].friendCount; i++) {
    temp[i] = hbook[index].friendList[i];
  }
  
  //delete the old, non-expanded list, make the new friendList the expanded one,
  //update friendCapacity, and tell caller that functino was successful.
  delete [] hbook[index].friendList;
  hbook[index].friendList = temp;
  hbook[index].friendCapacity *= 2;
  return true;
}  
    
/* destructor if you have time*/
HookBook::~HookBook()
{
    
}

bool HookBook::expandPirates()
{
    Pirate* temp = new Pirate[currentCapacity*2];
    if(temp == NULL){
        return false;
    }
    for (int i = 0; i < pirateCount; i++) {
        temp[i]=hbook[i];
    }
    delete[] hbook;
    hbook = temp;
    currentCapacity = currentCapacity*2;
    return true;
}

