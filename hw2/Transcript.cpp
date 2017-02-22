//-----------------------------------------------------------------------------
// Filename: Transcript.cpp
// Author:   Noah J. Epstein
// Date:     9/26/13
// Rev-Date: 9/26/13
//
// Description: Implementation of a "transcript" object. Transcripts contain 
//    			a student ID, a bunch of semesters as a dynamic array, all of
//				which hold courses, the number of semesters, and thecapacity of
//				the array. 
//
// Agknowledgements: I'd like to thank the academy. And Stack Overflow. 
//-----------------------------------------------------------------------------

#include "Transcript.h"

#include <iostream>
using namespace std;


//default constructs the emptiest transcript possible. the list is null, 
//capacity zero, and there are no semesters.
Transcript::Transcript()
{
	semList = NULL;
	capacity = 0; 
	nSemesters = 0; 
}

//makes a new list of semesters with a size of 14, but there are no semesters
//in there yet. (let's say this represents a freshman). so only a student ID
Transcript::Transcript(string ID)
{
	semList = new Semester[INIT_SEMS];
	
	//initial values
	capacity = INIT_SEMS;
	nSemesters = 0; 
	studentID = ID;
}


//if the list is NULL, we haven't 'new-d' it yet! it's empty.
bool Transcript::isEmpty()
{
	return semList == NULL; 
}


//returns private data member for SAFETY PURPOSES.
string Transcript::getID()
{
	return studentID;
}


//creates a new transcript on the heap - exactly a copy of the original 
//transcript. it expands a new transcript until it's big enough, then puts
//data in, using the copy constructor for semesters.
Transcript* Transcript::makeTransCopy()
{
	Transcript* copy = new Transcript(studentID);

	while (copy->capacity <= capacity) { 
		expand(); //because you can't put data off the end of the array.
	}

	for (int i = 0; i < nSemesters; i++){

		copy->semList[i] = semList[i]; //copy constructor for all the data
	}

	return copy;
}

//standard expand function. makes a bigger list with capacity n^2. if 
//it can't allocate memory, the whole thing fails. if it can, it copies the 
//data into the new, bigger array, and updates capacity. 
bool Transcript::expand()
{
	Semester* biggerList = new Semester[capacity *2];
	
	if (biggerList == NULL){ //if failed to allocate memory
		return false;        //then expand failed to expand.
	}

	for (int i = 0; i < nSemesters; i++){
		biggerList[i] = semList[i]; //copy data
	}

	delete [] semList; 		//delete the old one
	semList = biggerList;	//make way for new one!
	capacity *= 2;			//update capacity
	return true;			//it worked
}

//testing function to print out a transcript.
void Transcript::print()
{
	cout << "ID: " << studentID << endl;

	for (int i = 0; i < nSemesters; i++){
		
		cout << semList[i].getTerm() << ", " << semList[i].getYear() << endl;
		//cout << endl << semList[i].printCourses() << endl;
	}
}