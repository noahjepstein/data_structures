//-----------------------------------------------------------------------------
// Filename: Course.h
// Author: Noah J. Epstein
// Date: 9/29/13
// Rev-Date: 9/30/13
//
// Description: Header file for a "course".
// 
// Agknowledgements: None yet.
//-----------------------------------------------------------------------------

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
using namespace std;

class Course
{
public:

	Course(); //default, does nothing

	Course(string code, string grade); //creates a new course

	string getCourse_name(); //

	string getCourse_grade();

private:

	string courseCode;

	string courseGrade;

	bool isEmpty; 

};

struct CourseNode //the data structure behind the linked list!
{
	Course c;

	CourseNode* next;
};

#endif


