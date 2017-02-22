//      Tufts University
//      Document Created 9/5/13
//      Sequence With Linked List .h File - sequenceL.h
//      COMP15: Data Structures

//******************************************************************************

#ifndef sequences_sequenceL_h
#define sequences_sequenceL_h
#include <iostream>
#include <cstdlib>
using namespace std;

//******************************************************************************
// housekeeping: making structs for Linked List and setting typedef

typedef char ElementType;

struct Seq
{
    ElementType element;
};

struct Node
{
    Seq data;
    Node *next;
};
//******************************************************************************
// class description

class SequenceL
{
public:
    SequenceL();
    SequenceL(ElementType data);
    // ^^^ constructors
    
    bool isEmpty();
    // ^^^ takes in nothing, returns boolean specifying if sequence is empty
    
    int size();
    // ^^^ returns integer referring to the numbers of chars in the sequence
    
    void concatenate(SequenceL *newData);
    // ^^^ needs to take a pointer in
    
    ElementType first();
    // ^^^ returns first element of sequence
    
    SequenceL * rest();
    /* ^^^ returns a pointer to a sequence that is equivalent to the original
     except  the first character is no longer part of the sequence */
    
    void print();
    // ^^^ prints out the sequence to the screen
    
private:    
    
    Node *head;

    void quit(string error);
    // ^^^ function quits with string as error

    Node *copy(Node* head);
    // ^^^ copies a LL and returns the head of the new, copied LL
};

//******************************************************************************

#endif