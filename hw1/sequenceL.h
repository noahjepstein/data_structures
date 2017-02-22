//-----------------------------------------------------------------------------
// Filename: sequenceL.h
// Author:   Noah J. Epstein
// Date:     9/14/2013
// Rev-Date: 9/18/2013
//
// Description: "sequenceL.h" defines a 'sequence' data structure using 
//              linked lists. 
//
//              Includes two constructors, one to create an empty list, 
//              and one to create a list w/ a single element. The list is 
//              composed of a series of "Nodes" as described in "sequenceL.h".
//              Includes public members to determine emptiness, size, to
//              concatenate two lists, get the first element of the list, 
//              create a new list that excludes the first element of the 
//              original, and print the list. Private members include the list 
//              head itself, the list's size, and a helper function, 
//              "node_after_Seq".
//
// Agknowledgements: Piazza helps!
//-----------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
using namespace std;

typedef char ElementType; //so the data type can be changed

//A 'Node' struct is used to represent the "links" of a linked list: 
//within a node is included a data element, and a pointer to the next 
//link. 
struct Node
{
    ElementType data;

    Node* next;
};


class SequenceL
{
    public:
        
        SequenceL();              //constructs a sequence w/ no elems

        SequenceL(ElementType a); //constructs seqeuence w/ a as first elem

        bool isEmpty();           //returns true for an empty sequence

        int size();               //returns the size of the sequence

        void concatenate(SequenceL* seq2); //concatenates the Sequence w/ seq2

        ElementType first();      //returns the first character of a sequence
                                  //where calling first on an empty list will
                                  //cause the program to exit.

        SequenceL* rest();        //returns pointer to the rest of a sequence

        void print();             //prints the sequence to the screen

    private:

        Node* head;               //stores the head of the list

        int current_size;         //current length of the sequence

        Node* node_after_Seq();   //helper function for concatenate
};