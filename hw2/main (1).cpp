//-----------------------------------------------------------------------------
// Filename: main.cpp
// Author:   Noah J. Epstein
// Date: 9/30/13
// Rev-Date: 10/1/13
//
// Description: Tests TOT.cpp, Transcript.cpp, Semester.cpp, and Course.cpp.
//              There are four respective "mains". Comment in and out each one
//              individually to test that respective part of the program. Main
//              for Course testing only tests the course class, while main
//              for the Semester class tests both Semesters and Courses. The 
//              Transcript main tests Transcripts, Semesters, and Courses,
//              and TOT main tests TOT, Transcripts, Semesters, and Courses. 
//              Each data structure uses its subjugate data structures. 
//
// Agknowledgements: Thanks, Ben and TAs. 
//-----------------------------------------------------------------------------

#include "TOT.h"
#include "Transcript.h"
#include "Semester.h"
#include "Course.h"

#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//MAIN FOR TESTING TOT

int main()
{
    Transcript nje("123456");

    Semester s2("fall", 2013);
    Semester s3("spring", 2014);
    Semester s4("sum1", 2014);
    Semester s5("sum2", 2014);

    //make some test courses to put into semesters
    Course testCourses[5];
    testCourses[0] = Course("comp15", "A+");
    testCourses[1] = Course("math51", "F-");
    testCourses[2] = Course("ES3", "A");
    testCourses[3] = Course("ES5", "B+");
    testCourses[4] = Course("Mus21", "badabadaba");

    for (int i = 0; i < 5; i++){
        cerr << "hi";
        s2.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s3.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s4.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s5.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi" << endl;
    }

    /*
    Transcript a;
    Semester* sem; 

    a.addSemester(sem);

    //assign some semesters to each of the five transcripts. 
    for (int i = 0; i < 100; i++){
        nje.addSemester(&s2);
        nje.addSemester(&s3);
        nje.addSemester(&s4);
        nje.addSemester(&s5);
    }*/

    Transcript* t = nje.makeTransCopy();
    Transcript* n = t->makeTransCopy();

    Transcript l;

    for (int i = 0; i < 100; i++) {
        //l.addSemester(&s2);
    }



    cout << nje.getID() << endl
         << l.getID() << endl 
         << t->getID() << endl
         << n->getID() << endl;

    

    nje.print();
    l.print();
    t->print();
    n->print();

    TOT isis;

    Transcript* transcriptList = new Transcript[20];

    for (int i = 0; i < 20; i++){
        transcriptList[i] = nje;
    }

    TOT iSIS(transcriptList, 20);

    Transcript* test = iSIS.getTranscriptCopy("123456");
    test->print();
    iSIS.addTranscript(test);
    iSIS.print(); //isis is tested!
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/*
//MAIN FOR TESTING Transcript

int main()
{
    Transcript nje("123456");

    Semester s2("fall", 2013);
    Semester s3("spring", 2014);
    Semester s4("sum1", 2014);
    Semester s5("sum2", 2014);

    //make some test courses to put into semesters
    Course testCourses[5];
    testCourses[0] = Course("comp15", "A+");
    testCourses[1] = Course("math51", "F-");
    testCourses[2] = Course("ES3", "A");
    testCourses[3] = Course("ES5", "B+");
    testCourses[4] = Course("Mus21", "badabadaba");

    for (int i = 0; i < 5; i++){
        cerr << "hi";
        s2.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s3.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s4.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi";
        s5.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        cerr << "hi" << endl;
    }

    return;
    
    Transcript a;
    Semester* sem; 

    a.addSemester(sem);

    //assign some semesters to each of the five transcripts. 
    for (int i = 0; i < 100; i++){
        nje.addSemester(&s2);
        nje.addSemester(&s3);
        nje.addSemester(&s4);
        nje.addSemester(&s5);
    }

    Transcript* t = nje.makeTransCopy();
    Transcript* n = t->makeTransCopy();

    Transcript l;

    for (int i = 0; i < 100; i++) {
        //l.addSemester(&s2);
    }

    cout << "human ";

    cout << nje.getID() << endl
         << l.getID() << endl 
         << t->getID() << endl
         << n->getID() << endl;

    cout << "dancer" << endl;

    nje.print();
    l.print();
    t->print();
    n->print();

}
*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//MAIN FOR TESTING Semester
/*
int main()
{
	Semester s1; //empty semester, just to check

	//some semesters, hard coded and imaginary
    Semester s2("fall", 2013);
	Semester s3("spring", 2014);
	Semester s4("sum1", 2014);
	Semester s5("sum2", 2014);

    //make some test courses to put into semesters
    Course testCourses[5];
    testCourses[0] = Course("comp15", "A+");
    testCourses[1] = Course("math51", "F-");
    testCourses[2] = Course("ES3", "A");
    testCourses[3] = Course("ES5", "B+");
    testCourses[4] = Course("Mus21", "badabadaba");

    for (int i = 0; i < 5; i++){
        s2.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        s3.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        s4.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
        s5.addCourse(testCourses[i].getCourse_name(), 
            testCourses[i].getCourse_grade());
    }

	//test transcript to hold some semesters
    Semester* transTest = new Semester[60];

	//assign some semesters to each of the five transcripts. 
    for (int i = 0; i < 56; i += 4){
		transTest[i] = s2;
		transTest[i+1] = s3;
		transTest[i+2] = s4;
		transTest[i+3] = s5;
	}

	for (int i = 0; i < 14; i++){
		cout << "nCourses: " << transTest[i].getSize() << endl;
		cout << "semester: " << transTest[i].getTerm() 
			 << transTest[i].getYear() << endl;

		transTest[i].printCourses(); 
	}
}
*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/*
//MAIN FOR TESTING Course

#include <sstream>

int main()
{
	Course* c = new Course[25];

	for (int i = 0; i < 25; i++){
		stringstream i2char;
		i2char << "comp" << (i + 1);
		c[i] = Course(i2char.str(), "A++");
	}

	for (int i = 0; i < 25; i++){
		cout << c[i].getCourse_name() << ": " 
		     << c[i].getCourse_grade() 
		     << endl;
	}
}
*/

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

