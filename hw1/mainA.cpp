//
// Filename: main.cpp
// Author:   Noah J. Epstein
//
// Description: Testfile for sequenceA and sequenceL
//

#include "sequenceA.h"

int main()
{
	SequenceA s1; 
	SequenceA s2('x');
	SequenceA s3('y');
	SequenceA s4('z'); 

	//SequenceA* s1p = &s1;
	SequenceA* s2p = &s2;
	SequenceA* s3p = &s3;
	//SequenceA* s4p = &s4; 

    for (int i = 0; i < 25; i++){
        s1.concatenate(s2p);
        s2.concatenate(s2p);
    }
    

	s1.print(); 
	s2.print();
	s3.print();
	s4.print(); 

    return 0;
}


