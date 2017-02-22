//-----------------------------------------------------------------------------
// Filename:         TOT.h
// Author:           Noah J. Epstein
// Date:             9/25/13
// Rev-Date:         9/25/2013
// 
// Description:      header file for transcripts
//
// Agknowledgements: None yet.
//-----------------------------------------------------------------------------

#ifndef TOT_H
#define TOT_H


#include "Transcript.h" //keep it as Transcript.h?


//initial size of dynamic array of ptrs to transcripts
const int INIT_SIZE = 5;

//factor to increase size of array
const int EXP_FACTOR = 2; 

class TOT
{
public:

    //constructor creates dynamic array of size INIT_SIZE, sets pointers to NULL
    TOT();

    //constructor takes in a dynamic array of transcripts, 
    //note you may call addTranscript function
    TOT(Transcript* transcriptList, int listSize);
 
    //Function returns a pointer to a copy of student’s transcript
    Transcript* getTranscriptCopy(string studentID);
    
    //function adds a single Transcript to the end of the system's array,
    //returns bool if it worked
    bool addTranscript(Transcript* t);

    void print(); //print function for viewing output
 
 private:
 
    //dynamic array of pointers to Transcripts
    Transcript** transcripts;
 
    Transcript* lookUp(string sID);
 
    //expand dynamic array when it is full
    bool expand();

    //count of how many currently stored
    int currentCount;

    //capacity of the dynamic array
    int currentCapacity;
 
 };

 #endif

