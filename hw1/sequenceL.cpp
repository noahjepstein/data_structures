//-----------------------------------------------------------------------------
// Filename: sequenceL.cpp
// Author:   Noah J. Epstein
// Date:     9/13/2013
// Rev-Date: 9/18/2013
//
// Description: Implementation of a sequence class using linked lists.
//              Includes two constructors, one to create an empty list, 
//              and one to create a list w/ a single element. The list is 
//              composed of a series of "Nodes" as described in "sequenceL.h".
//              Includes public membersto determine emptiness, size, to
//              concatenate two lists, get the first element of the list, 
//              create a new list that excludes the first element of the 
//              original, and print the list. Private members include the list 
//              head itself, the list's size, and a helper function, 
//              "node_after_Seq".
//
//              Yes, it's very buggy. However, I believe the general algorithms
//              are correct, and the bugs exist mostly because of limited time
//              and sleep. Thank you!
//
// Agknowledgements: Piazza helps!
//-----------------------------------------------------------------------------

#include "sequenceL.h"


//default constructor for a linked list. 
SequenceL::SequenceL()
{
    head = NULL; //empty lists are NULL

    current_size = 0; //empty lists have size 0
}


//overloaded constructor that creates a list with first element a 
SequenceL::SequenceL(ElementType a)
{
	head = new Node; //unlike with the empty sequence, this head needs a Node

	head->data = a; //the data in the head is assigned a
	head->next = NULL; //but the node, as it's the only one, points to null

    current_size = 1; //only one element in this list
}


//determines whether the list is empty. returns true if empty, if not, false.
bool SequenceL::isEmpty()
{
	return head == NULL; // one liner!!
}



//returns the size of a sequence. uses an iterator and counter to move down
//the list, counting each element without disturbing the data or connections.
int SequenceL::size()
{
	Node* iter = head; //creates iterator
	int size = 0; //before counting, there are no elements.

	//if the list is empty, the while loop condition will fail and size() will
    //return 0. if not, it will count each element.
    while (iter != NULL) {
		iter = iter->next;
		size++;
	}

	return size;
}


//appends a newSeq to the end of the existing sequence - doesn't
//just tie the end of the list to the head of newSeq.
void SequenceL::concatenate(SequenceL* newSeq)
{
	if (newSeq->isEmpty()) { 
		//adding an empty sequence to the end of a sequence yields no result.
        //as such, here we do nothing
        return; 

	} else {
        //we will start concatenating at the end of the preexisting sequence
        //which can either be at the beginning, or at the middle.
        Node* iter1 = node_after_Seq(); 
        Node* iter2 = newSeq->head; //iter2 starts with the seq to copy

        while (iter2 != NULL) {
           
            iter1->data = iter2->data; //copies data
           
            //if the original doesn't end, put a new node on the copy so you can 
            //insert some data into the node.
            if (iter2->next != NULL) {
                iter1->next = new Node; 
            } else {
                iter1->next = NULL; //if you're at the end, end the copy, too.
            }

            iter1 = iter1->next; //increment iterator
            iter2 = iter2->next; //increment iterator
        }
    }
    current_size += newSeq->size(); //current size increases by newSeq->size()
}


//finds the end of a sequence, creates a node at the end - a point at which
//a new sequence can be appended
Node* SequenceL::node_after_Seq()
{
    if (isEmpty()) { //create a starting node for a new list
        Node* head = new Node;
        return head;
    
    } else { //go down the list until you've reached the end of the current
             //data, then put a new node at the end where you can append a 
             //newSeq
        Node* iter = head;

        while (iter->next !=NULL) {
            iter = iter->next; //if you're not at the end, increment
        }

        iter->next = new Node;
        return iter->next; //put new node at end and return the new node
    }
}


//first will exit the program when called on an empty list.
//otherwise, it returns the first element, which may or may not be 
//the only element.
ElementType SequenceL::first()
{
    if (isEmpty()) {
        exit(1); //exits program
    } 

    return head->data; //returns first element
}



//rest returns a pointer to a NEW list that's an exact copy of the list,
//except it excludes the list's first element. i.e. the "rest"
SequenceL* SequenceL::rest()
{
    SequenceL* rest = new SequenceL; //rest is a completely new sequence

    Node* iter1;
    Node* iter2; 

    rest->head = new Node; //the new sequence needs a new head

    iter1 = rest->head; //iter1 keeps track of the list to which we'll copy
    iter2 = head->next; //iter2 starts at the 2nd element on the original list

    while (iter2 != NULL) {
       
        iter1->data = iter2->data;  //copy the data into the new list
       
        if (iter2->next != NULL) {
            iter1->next = new Node; //if list continues, make a new copy node
        
        } else {
            iter1->next = NULL; //if list ends, copy the NULL ending
        }
        
        //continue along list
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    rest->current_size = size() - 1; //rest is 1 element smaller than original
    return rest;
}


//iterates through elements with an iterator, printing each,
//until the end of the list is reached, at which point the func prints
//a new line.
void SequenceL::print()
{
    Node* iter = head;

    while (iter != NULL) {
        
        //iter will proceed down the list, starting at the 
        //beginning, printing all data elements on a single line
        //until iter reaches the end of the list.
        cout << iter->data;  //NOTE: for some reason, accessing the nodes
        iter = iter -> next; //when in the print function causes a seg fault
    }
    cout << endl;
}
