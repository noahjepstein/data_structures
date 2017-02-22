/*
 * main.cpp -- test the Sequence implementations
 *
 * IMPORTANT: This file is generic and will be converted into two versions
 *  one version called mainL.cpp and one called mainA.cpp
 *
 *  Those two can be compiled with the specific header files
 *  and then linked with the implementation files
 *
 *  The conversion is simple, use SequenceX for sequenceA or sequenceX 
 *  ==== do not delete this line
 */

#include <iostream>
#include "sequenceL.h"	

using namespace std;

/* 
    Purpose: Test to see if we can print a single character. 
    Utilizes overloaded constructor.
    Pre-condition:
    Post-condition:
*/
void printTest1()
{
	cout << "test print for 1-item list" << endl;   // state purpose

	SequenceL s('a');				// make a sequence
	cout << "Expected: a returned: "; 		// what we want
	s.print();					// what we get
	cout << endl;
}


/*
    Purpose: Test to print a many-item list of characters
    Utilizes overloaded constructor and concatenate
    Pre-cond: //
    Post-cond: //
*/
void printTest2()
{
    cout << "test print for many-item list" << endl;
    
    SequenceL s1('a');
    SequenceL s2('b');
    
    for (int i = 0; i < 3; i++){
	s1.concatenate(&s2);
	s2.concatenate(&s1);
    }
    
    cout << "expected: a b b a b b a b a b b a b   returned: ";
    s1.print();
    cout << "expected: b a b a b b a b a " 
	 << "b b a b b a b a b b a b  returned: ";
    s2.print();
}


/* 
    Purpose: Test to see if we can concatenate with another 
	sequence N number of times
    Pre-condition:
    Post-condition:
*/
void expandTest1(int elements)
{
	cout << "test expand(concat another sequence n times" << endl;

	SequenceL* seq1 = new SequenceL('a');		// make a sequence
	SequenceL* seq2 = new SequenceL('b');		// and another

	for(int i = 0; i < elements; i++){		// add 'em on
		seq1->concatenate(seq2);
	}

	// report results
	cout << "expected: a followed by " << elements << " b's returned: "; 
	seq1->print();

	cout << endl;
}

int main(){

	cout << "==========v Constructor Tests v=======" << endl;
	
	SequenceL a; 
	cout << "constructed empty seq" << endl;
	
	SequenceL* b = new SequenceL;
	cout << "constructed another empty seq" << endl;
	
	SequenceL c('a');
	SequenceL d('1'); 
	SequenceL e('t');
	cout << "constructed a few non-empty seqs w/ overloaded constructor" << endl;
	
	cout << "==========^ Constructor Tests ^=======" << endl << endl;

	cout << "==========v isEmpty Tests v=======" << endl;
	
	if (a.isEmpty()){
	  cout << "empty sequences are empty. default constructor works" << endl;
	}
	
	if (b->isEmpty()) {
	  cout << "empty sequences are still empty. default con works" << endl;
	}
	
	if (!c.isEmpty()) {
	  cout << "i guess the overloaded constructor works" << endl;
	}
	
	cout << "==========^ isEmpty Tests ^=======" << endl << endl;;

	cout << "==========v print() Tests v=======" << endl;
		printTest1();
		printTest2();
	cout << "==========^ print() Tests ^=======" << endl << endl;;
			
	cout << "==========v size() Tests v=======" << endl;
	
	SequenceL s1;
	SequenceL s2('a');
	
	cout << "expected size: 0" 		<< endl 
	     << "returned size: "  << s1.size() << endl
	     << "expected size: 1" 		<< endl
	     << "returned size: "  << s2.size() << endl;
	     
	for (int i = 0; i < 10; i++){
	     cout << "Expected size: " << i << "  returned size: "
	          << s1.size() << endl;
	     s1.concatenate(&s2);
	}
	
	SequenceL s3; 
	
	for (int i = 0; i < 1000000; i++){
	  s3.concatenate(&s2);
	}
	
	cout << "expected size: 1000000   returned size: " << s3.size()
	     << endl;
	
	cout << "==========^ size() Tests ^=======" << endl << endl;;
	
	
	cout << "==========v first() Tests v=======" << endl;
	
	    //many item list 
	    cout << "expected: a  returned: " << s1.first() << endl;
	    
	    //single-item list
	    cout << "expected: a  returned: " << s2.first() << endl;
	    
	    //empty list 
	    SequenceL s4;
	    cout << "expected:  returned: " << s4.first();
	
	cout << "==========^ first() Tests ^=======" << endl;
	
	cout << "==========v rest() Tests v=======" << endl << endl;;
	cout << "==========^ rest() Tests ^=======" << endl << endl;

	cout << "==========v concatenate() Tests v=======" << endl;
	cout << "==========^ concatenate() Tests ^=======" << endl << endl;
		
	cout << "==========v expand Tests v=======" << endl;
		expandTest1(1000);
	cout << "==========^ expand Tests ^=======" << endl << endl;;
	
	
	return 0;
}
