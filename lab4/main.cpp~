/* main.cpp
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */
 
#include "sandwichList.h"
#include <iostream>
using namespace std;

int main(){

  SandwichList slist;
  Order testCases[15];
  Order temp;

  string s = "sandwich";
  string c = "customer";

  // generate 15 test cases
  for(int i = 0; i < 15; i++){
      testCases[i].sandwich = s;
      testCases[i].customerName = c;
      testCases[i].orderNbr = i;
      testCases[i].fries = i%2;
  }

	//add one
  slist.add(testCases[0]);

	//remove one
  temp = slist.getNext();
	
  // see if sandwich customer 0 0 is a match with itself
  slist.printOrder(testCases[0]);
  cout << "matches" << endl;
  slist.printOrder(temp);
  cout << endl;

	// 10 times add two and remove one, which adds 1, 1, 2, 2, ... 9, 9
	// and removes the first 10, which would be 1, 1 - 4, 4
  for(int i = 0; i < 10; i++){
      slist.add(testCases[i]);
      slist.add(testCases[i]);
      temp = slist.getNext();
  }
  
  cout << "Should print customers 5-9 twice each, then empty Q message:\n";
  
	// Print customers 5, 5, 6, 6, ... 9, 9, then print empty message
  for(int i = 0; i < 11; i++){
    if(!slist.isEmpty()){
	  temp = slist.getNext();
	  slist.printOrder(temp);
	}
	else
	  cout << "Q empty - no more sandwiches" << endl;
  }

	// add 15 Orders to test expansion
	for(int i = 0; i < 15; i++)
		slist.add(testCases[i]);
		
  return 0;
}
