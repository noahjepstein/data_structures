//File name: sequenceL.h
//Last edited Sept 17th 2013
//creates a class to be used by sequenceL.cpp

#include <iostream>
using namespace std;

typedef char ElementType;

//struct containing one predefined element of ElementType
//and a pointer either to next node or to NULL
//linked lists in .cpp are made of these structs
struct listNode {
    ElementType data;
    listNode *link;
};

//class definition used by sequenceL.cpp
class SequenceL {
	public: 
    		//constructor called if no elements are given
    		//sets head to NULL
    		SequenceL();
		//overload constructor called when one element a is given
		//sets data to a and link to NULL
		SequenceL(ElementType a);
		//checks if head of list is NULL meaning list has no nodes
    		bool isEmpty();
		//loops through list counting number of nodes
		//called when the size of list is needed aka when
		//list is being copied, etc.
    		int size();
		//adds copy of new linked list sequence
		//to existing linked list sequence
    		void concatenate(SequenceL* Seq);
		//gives first element in list
		ElementType first();
		//copies sequence into new linked list
		//without the first element
    		listNode* rest(); 
		//prints out linked list sequence
    		void print();
	private:
		//used by concatenate to make a copy of a given sequence
		//so that the sequence isn't itself changed
		listNode* copy(SequenceL* seq, listNode* newLL);
		//used by copy and rest to copy a sequence 
		//into a linked list
		listNode* copyAfter(listNode* newLL, listNode* iter, 
			listNode* iter2);
		//called by size to loop through linked list
		//and count up number of nodes while link isn't null
		int sizeHelper(); 
		//defines head as a pointer to a listNode
		//used at the beginning of the linked list
		listNode* head;
};
