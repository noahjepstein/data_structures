//-----------------------------------------------------------------------------
// Filename: Semester.cpp
// Author:   Noah J. Epstein
// Date:     9/29/13
// Rev-Date: 9/30/13
//
// Description: Implementation of a "semester" object, that consists of 
//
// Agknowledgements: I'd like to thank the academy, and iSIS. And Ben + TAs.
//-----------------------------------------------------------------------------

#include "Semester.h"

#include <iostream>
#include <cstdlib>
using namespace std;


//default constructor
Semester::Semester()
{
	nCourses = 0; //no courses
	head = NULL; //no list
	tail = head; //tail is also null
}

//overload constructor that initializes term and year, but nothing else
Semester::Semester(string trm, int yr)
{
	nCourses = 0; 
	term = trm; 
	year = yr;
	head = NULL;
	tail = head;
}


//copy constructor for semesters. all the simple data members are
//copied directly. the linked list is created using addCourse. 
Semester::Semester(const Semester &sem)
{
    nCourses = sem.nCourses;    //copy sem's data elems into this
    term = sem.term;            
    year = sem.year;

    CourseNode* iter = sem.head;

    if (sem.head == NULL) { //well, there's nothing in an empty semester
        head = NULL;
        tail = head;
    
    } else {
        while (iter != NULL) {
            //add all the courses in sem to the new semester
            addCourse(iter->c.getCourse_name(), iter->c.getCourse_grade());
            iter = iter->next;
        }
    }
}



//it's empty if there are no courses in it.
bool Semester::isEmpty()
{
	return (nCourses == 0);
}


//addCourse acts as a directing funciton for two helper functions.
//you can either start a new list, or add to an existing one.
void Semester::addCourse(string courseName, string courseGrade)
{
	if(isEmpty()){
		startList(courseName, courseGrade); 
	
	} else {
		addtoEnd(courseName, courseGrade);
	}
}



//creates the first node in the list and puts data in it. 
//if there's one data element, coincidentally the head is the tail.
void Semester::startList(string courseName, string courseGrade)
{
	//create a new head, which for size = 1, is the same as the tail
	head = new CourseNode;
	tail = head;

	//put a Course in the list. it doesn't have a next yet.
	head->c = Course(courseName, courseGrade);
	head->next = NULL;
	nCourses++; //and then there was one.
}


//sticks a new node on the end of a preexisting list of courses.
void Semester::addtoEnd(string courseName, string courseGrade)
{
	//stick a new piece of data on the end and update the tail
	tail->next = new CourseNode;
	tail = tail->next; 

	//put some data in the new tail
	Course newCourse(courseName, courseGrade);
	tail->c = newCourse;
	tail->next = NULL;

	nCourses++; //you added a course, update the number.
}


//another copy-making function. since you don't want to return a NULL
//semester (and risk some crazy stuff later), if you try to copy an empty
//list, the program crashes.
Semester* Semester::makeCopy()
{
    if (isEmpty()){
        exit(1); //can't copy empty list
    }

    Semester* copy = new Semester(term, year);
    CourseNode* iter = head;

    while (iter != NULL) {
        //adds courses to the linked list of copy
        copy->addCourse(iter->c.getCourse_name(), iter->c.getCourse_grade());
        iter = iter->next;
    }
    return copy; //returns it
}


//lemme see the private data! no touching, please.
int Semester::getSize()
{
    return nCourses;
}


//lemme see the private data! but no touching, please.
string Semester::getTerm()
{
    return term;
}


//private data. you can see, but can't touch. 
int Semester::getYear()
{
    return year;
}


//printCourses function for testing Semesters. doesn't print anything for 
//an empty list.
//SAMPLE FORMAT: comp15: A+
void Semester::printCourses()
{
    CourseNode* iter = head; 

    while (iter != NULL){
        //iterate through and 
        cout << iter->c.getCourse_name() << ": "
             << iter->c.getCourse_grade() << endl;
        iter = iter->next;
    }
}

