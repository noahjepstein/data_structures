//-----------------------------------------------------------------------------
// Filename: Course.cpp
// Author:   Noah J. Epstein
// Date:     9/29/13
// Rev-Date: 9/30/13
// 
// Description: Implementation of "Course" class.
// 
// Agknowledgements: None yet.
//-----------------------------------------------------------------------------

#include "Course.h"

#include <iostream>
using namespace std;


//i've been told that default constructors are a good idea, but 
//this one doesn't do anything
Course::Course()
{

}


//a course has a name, grade, and emptiness value
Course::Course(string code, string grade)
{
	courseCode = code; 
	courseGrade = grade;
	isEmpty = false;
}


//for seeing private data
string Course::getCourse_name()
{
	return courseCode;
}


//for seeing private data
string Course::getCourse_grade()
{
	return courseGrade;
}
