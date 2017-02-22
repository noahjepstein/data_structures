//-----------------------------------------------------------------------------
// Filename: Transcript.h
// Author:   Noah J. Epstein
// Date:     9/25/13
// Rev-Date: 9/25/13
//
// Description: Header file for a Transcript. See Transcript.cpp for more info
//
// Agknowledgements: I'd like to thank my family. 
//-----------------------------------------------------------------------------

#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#include "Semester.h"


const int INIT_SEMS = 14;


class Transcript
{
public: 

	Transcript(); //default constructor

	Transcript(string ID); //overlaoded constructor, starts w/ student ID

	string getID(); //returns copy of the ID

    bool isEmpty(); //determines whether transcript has semesters in it

    void addSemester(Semester* sem); //adds a semester to the list

	Transcript* makeTransCopy(); //makes a copy, returns a transcript ptr

	void print(); //print function for testing

private: 

	int nSemesters;

	int capacity;

	string studentID; 

	Semester* semList; //dyn array of semesters

	bool expand(); //for expanding the dynamic array of semesters

};

#endif
