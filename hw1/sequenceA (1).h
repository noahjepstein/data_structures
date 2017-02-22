//-----------------------------------------------------------------------------
// Filename: SequenceA.h
// Author:   Noah J. Epstein
// Date:     9/14/2013
// Rev-Date: 9/18/2013
//
// Description: "sequenceA.h" defines a 'sequence' data structure using 
//              dynamic arrays.
//
//              Includes two constuctors: one to create an empty sequence,
//              and one to create a sequence with one element. Includes public
//              members to determine emptiness, size, to concatenate two lists,
//              get the first element of the list, create a new list that
//              excludes the first element of the original, and print the list.
//              Includes private data members: the sequence itself, a boolean
//              that stores the sequence's emptiness, and capacity and size 
//              variables for the sequence. Includes an expand functino for 
//              increasing the capacity of the array. Includes appendtoSeq, 
//              a helper fuction for concatenate.
//
// Agknowledgements: Piazza helps!
//-----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElementType; //so ElementType can be changed

class SequenceA
{
    public:
        
        SequenceA();       //constructs a sequence w/ no elems

        SequenceA(ElementType a); //constructs seqeuence w/ a as first elem

        bool isEmpty();   //returns true for an empty sequence

        int size();       //returns the size of the sequence

        void concatenate(SequenceA* newSeq); //concatenates the Sequence w/ seq2

        ElementType first();     //returns the first character of a sequence

        SequenceA* rest(); //returns pointer to the rest of a sequence

        void print();     //prints the sequence to the screen

    private:

        ElementType* Seq;      //a Seq is a pointer to an ElementType

        bool is_empty;         //private variable keeps track of emptiness

        int current_size;      //current length of the sequence

        int current_capacity;  //current capacity of the sequence

        void expand(int n);    //expands capacity to fit size n

        void appendtoSeq(SequenceA* newSeq); //appends newSeq to Seq
};

