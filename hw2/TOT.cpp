//-----------------------------------------------------------------------------
// Filename: TOT.cpp
// Author:   Noah J. Epstein
// Date:     9/25/13
// Rev-Date: 9/25/13
//
// Description: Implementation of TOT public and private members.
//
// Agknowledgements: None yet. 
//-----------------------------------------------------------------------------

#include "TOT.h"
#include "Transcript.h"

#include <iostream>
#include <cstdlib>
using namespace std;


//default constructor for TOT. creates an empty TOT with no transcripts
//in it. 
TOT::TOT()
{
    transcripts = new Transcript* [INIT_SIZE]; //starts list, does not fill

    currentCount = 0; //there's no stuff in it
    currentCapacity = INIT_SIZE; //but the array has a capacity
}


//takes in a dynamic array of transcripts and its size. makes a new TOT
//with listsize elements and listsize capacity. copies all the transcripts
//in the transcriptList into the local dynamic array, "transcripts". 
TOT::TOT(Transcript* transcriptList, int listSize)
{
    transcripts = new Transcript* [listSize]; //a fresh list

    currentCount = listSize; //we haven't put them in yet, but we will!
    currentCapacity = listSize; 

    for (int i = 0; i < listSize; i++){
        //so you can iterate through an array of transcript*s...with INTS
        addTranscript((transcriptList + i)->makeTransCopy());
    }
}


//calls makeTransCopy on the appropriate transcript as determined by the
//lookup function.
Transcript* TOT::getTranscriptCopy(string studentID)
{
    return lookUp(studentID)->makeTransCopy(); //one liner!
}


//adds a transcript to the TOT system. if the tot system doesn't have
//space for the new one, expand it. when it has space, add a copy of the
//transcirpt to the end of the list.
bool TOT::addTranscript(Transcript* t)
{
	if (currentCount == currentCapacity) { //if we full
        if (!expand()) {
            return false; //if expand fails, we'll fail to add. 
        }
    }
    Transcript* toAdd = t->makeTransCopy(); //makes a ptr to COPY of t.
    
    transcripts[currentCount] = toAdd; //adds the pointer to the list.

    return true; //we did it!
}


//looks up a transcript in TOT that matches a student ID # "sID". 
//parses through the array until it finds a matching transcript, then 
//returns its pointer. 
//if the sID is not in the list, THE PROGRAM EXITS. YOU CANNOT CALL lookUp 
//on an empty list.
Transcript* TOT::lookUp(string sID)
{
    for (int i = 0; i < currentCount; i++){
       
        //when you find the transcript matching sID, return a pointer to it
        if (transcripts[i]->getID() == sID) {
            return transcripts[i];
        }
    }
    exit(1); //if control gets here, the transcript could not be found. exit!
}


//function expands dyn array by factor of two. copies original array into
//a new array with twice the capacity, deletes the old one, and gives the
//new array the name of the original. Updates capacity of list to reflect
//changes to the capacity of the array. returns false if memory cannot be
//allocated.
bool TOT::expand()
{
	Transcript** biggerList = new Transcript * [currentCapacity * 2];

    if (biggerList == NULL) {
        return false; //mem cannot be allocated
    }

    //copies old array into new, bigger array
    for (int i = 0; i < currentCount; i++){
        biggerList[i] = transcripts[i]; 
    }

    currentCapacity += 2; //update capacity
    delete [] transcripts; //delete old
    transcripts = biggerList; //rename new, essentially
    return true; //hey, we did it!
}


//simple print function for viewing output. prints the entire member array
//of transcripts using transcript::print(). 
void TOT::print()
{
    for (int i = 0; i < currentCount; i++){
        transcripts[i]->print();
    }
}
