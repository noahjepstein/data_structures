//File name: sequenceA.h
//last edited Sept 17th 2013
//defines class SequenceA to be used by sequenceA.cpp

#include <iostream>
using namespace std;

typedef char ElementType;

const int INITIAL = 1; //arrays will becreated with size 1

//definition of class used by sequenceA.cpp
class SequenceA {
	public:
    		//creates an empty array
    		SequenceA();
		//overloaded constructor
		//creates an array of 1 element set to a
    		SequenceA(ElementType a);
		//uses int space to check if array has any elements
   		bool isEmpty();
		//checks size of variable space and returns as int
   		int size();    
		//adds elements in given sequence to existing 
		//array of elements
    		void concatenate(SequenceA* seq);
		//returns first element in array
    		ElementType first();
		//makes a new array and copies old array into it
		//without the first element of the array
    		SequenceA* rest();
		//prints out array
    		void print();
	private:
		//defines ETarray as pointer to ElementType
		//later used in .cpp as array name
		ElementType* ETarray;
		//defines temp as pointer to ElementType
		//also used in .cpp as array name
		ElementType* temp;
		//keeps track of how many spaces in array are filled
		//updated by functions in sequenceA.cpp
		int space;
		//keeps track of how many spaces total exist in array
		//updated by functions in sequenceA.cpp
		int maxSpace;
		//takes an array and creates an array twice the size
		//then copies old array into new one
	        //used by concatenate if new sequence is too big to add
		void expand();
};





	
 
