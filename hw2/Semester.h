//-----------------------------------------------------------------------------
// Filename: Semester.h
// Author:   Noah J. Epstein
// Date: 9/29/13
// Rev-Date: 9/30/13
//
// Description: Description of a 'semester' class 
//
// Agknowledgements: None yet.
//-----------------------------------------------------------------------------

#ifndef SEMESTER_H
#define SEMESTER_H

#include "Course.h"


class Semester
{
public:

	Semester(); //default

	Semester(string term, int year);

	Semester(const Semester &sem);

	bool isEmpty(); //are there courses in this semester?

	void addCourse(string courseName, string courseGrade); //add a course

	Semester* makeCopy(); //returns a pointer to a copy of a semester

	int getSize(); //returns private data copy

	string getTerm(); //returns private data copy

	int getYear(); //returns private data copy

	void printCourses(); //prints out all courses in a single semester. only for tests

	//Semester& operator=(const Semester& sem); //was going to put an assignment operator
	//but decided unnecessary

private:

	//starts a new linked list of courses w/ a node consisting of 
	//courseName and courseGrade
	void startList(string courseName, string courseGrade);

	//adds a node of courseName and coursegrade to the end of the linked
	//list of courses.
	void addtoEnd(string courseName, string courseGrade);

	int nCourses; //length of the list

	string term;

	int year;

	CourseNode* head;

	CourseNode* tail;


};

#endif
