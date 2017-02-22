//-----------------------------------------------------------------------------
// Filename: SequenceA.cpp
// Author:   Noah J. Epstein
// Date:     9/13/2013
// Rev-Date: 9/18/2013
//
// Description: Implementation of a sequence class using dynamic arrays. 
//              Includes two constuctors: one to create an empty sequence,
//              and one to create a sequence with one element. Includes public
//              members to determine emptiness, size, to concatenate two lists,
//              get the first element of the list, create a new list that
//              excludes the first element of the original, and print the list. 
//              Includes private data members: the sequence itself, a boolean
//              that stores the sequence's emptiness, and capacity and size 
//              variables for the sequence. Includes an expand functino for 
//              increasing the capacity of the array. Includes appendtoSeq, 
//              a helper fuction for concatenate.
//
//              Yes, it's very buggy. However, I believe the general algorithms
//              are correct, and the bugs exist mostly because of limited time
//              and sleep. Thank you!
//              
//
// Agknowledgements: Piazza helps!
//-----------------------------------------------------------------------------

#include "sequenceA.h"

const int INIT_CAPACITY = 10;   //initial capacity of the dynamic array
const int EXPANSION_FACTOR = 2; //


//default construtor for a sequence, giving the dynamic array INIT_CAPACITY
//spaces and setting all capacities to initial values, but leaving the array
//empty and uninitialized. 
SequenceA::SequenceA()
{
    Seq = new ElementType[INIT_CAPACITY]; //creates dynamic array

    is_empty = true;    
    current_size = 0; 
	current_capacity = INIT_CAPACITY; 
}


//overloaded constuctor for Seq that creates a Seq still w/ INIT_CAPACITY but 
//with a first element a. sets appropriate initial values.
SequenceA::SequenceA(ElementType a)
{
    Seq = new ElementType[INIT_CAPACITY];

	Seq[0] = a; //constructing sequence w/ single elem 'a'

    is_empty = false;
    current_size = 1; 
    current_capacity = INIT_CAPACITY;
}


//isEmpty returns a boolean to tell whether the list is empty
//which, conicidentally, is a private boolean that's changed whenever
//the list switches from empty to non/empty. 
bool SequenceA::isEmpty()
{
    return is_empty;
}


//size returns the size of the array (the nubmer of elements). 
//we keep track of the size as a private integer current_size. 
int SequenceA::size()
{
    return current_size;
}


//concatenate deals with four cases:
//      1. empty + empty = empty
//      2. Seq + empty = Seq (original)
//      3. empty + Seq = Seq (new)
//      4. Seq + Seq = different Seq
//1 and 2 are caputred by the first and second if statements, which both return
//and do nothing to the original sequence. 
//3 and 4 use appendtoSeq().
void SequenceA::concatenate(SequenceA* newSeq)
{
    if(newSeq->isEmpty()) {
        //nothing happens when you add an empty Seq to an existing
        //one, whether the existing Seq is empty or not.
        return; 
    
    } else if (newSeq == NULL) {
       
        return;

    } else {

        //there are two cases involved when appending a non-empty newSeq 
        //to an existing Seq: appending newSeq to an empty Seq, and appending
        //newSeq to the end of a non-empty Seq. appendtoSeq deals with both.
        appendtoSeq(newSeq);
    }
}


//appendtoSeq connects a newSeq to an existing Seq - if this func is called, 
//newSeq is automatically non-empty. the func expands the array if necessary, 
//finds where to start copying newSeq into Seq  (which may be at the beginning)
//and copys it in. It then updates the size of Seq.
void SequenceA::appendtoSeq(SequenceA* newSeq)
{
    //expands Seq to fit the current data length + new data length
    if (newSeq->size() + current_size > current_capacity){
        expand(newSeq->size() + current_size); 
    }
        
    for (int i = 0; i < newSeq->size(); i++){
     
        //j == index of array after last elem of Seq
        int j = current_size; 

        Seq[j] = newSeq->Seq[i];
        j++;
    }
    current_size += newSeq->size();
}


//expand increases the size of the dynamic array by EXPANSION_FACTOR
//until the array will fit n elements. 
void SequenceA::expand(int n)
{
    ElementType* temp;
    int original_capacity = current_capacity; 

    //expands array until its size will fit 'n' elements
    while(current_capacity < n){

        temp = new ElementType[current_capacity * EXPANSION_FACTOR];
        current_capacity*= EXPANSION_FACTOR;
    }

    //copies old array into temp array if expansion occurred
    for(int i = 0; (i < original_capacity) && (original_capacity < n); i++){
        temp[i] = Seq[i]; 
    }

    //deletes memory of old array; reassigns Seq to temp
    delete [] Seq;
    Seq = temp;
}


//print uses a for loop to print all elements in a Seq to the screen.
void SequenceA::print()
{
    //loops to print all elements of ElementType to screen
    for(int i = 0; i < size(); i++){
        cout << Seq[i]; 
    }
    cout << endl;
}


//first returns the first element of the Seq if first is called on an empty
//list, the program exits.
ElementType SequenceA::first()
{
    ElementType first;

    if (isEmpty()) {
        exit(1); //calling first on an empty list exits the program
    }

    first = Seq[0]; //first is the first elem in the Seq
    return first;
}


//rest returns a pointer to a NEW sequence that includes all elements
//but the first element of the original sequence. 
SequenceA* SequenceA::rest()
{
    SequenceA* rest = new SequenceA;

    //the rest of an empty sequence or a sequence of size 1 is NULL
    if (current_size <= 1) {
        return rest;
    } else {
       
        if (rest->current_capacity < current_capacity){
            //because rest only needs to fit current_size - 1 elems
            rest->expand(current_size - 1); 
        }
       
        //starts at 1 because it only needs to fill (current_size - 1) spots
        for (int i = 1; i < current_size; i++){ 

            //the 1st element of rest, rest->Seq[0], gets the 2nd
            //value of Seq, Seq[1], thus 
            rest->Seq[i - 1] = Seq[i];
        }

        //the size of the rest is one less than the current size
        rest->current_size = current_size - 1;

        return rest; //returns the pointer, not rest itself
    }
}
