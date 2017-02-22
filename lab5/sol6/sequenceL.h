#include <iostream>
using namespace std;
typedef char ElementType;

struct Node
{
    ElementType value;
    Node * next;
};

class SequenceL
{
public:
    //This is the default constructor
    //and it creates an empty sequence
    SequenceL();
    
    //This is a constructor that takes
    //a char, creates an empty sequence,
    //and sets the char as the first element
    SequenceL(ElementType data);
    
    //isEmpty takes in no parameters and returns
    //a bool with either true for an empty sequence
    //and false for a non-empty sequence by checking
    //if the private seqSize is 0
    bool isEmpty();
    
    //size takes in no parameters and returns the
    //size of the sequence which is stored in a
    //private integer called seqSize
    int size();
    
    //concatenate reads in a a pointer to another
    //sequence and attaches it to the end of the first sequence
    void concatenate(SequenceL *seqptr);
    
    //print will go through the sequence
    //and print every character leaving spaces in between
    void print ();
    
    //first returns the first character in the sequence
    ElementType first();
    
    //rest returns a pointer to a new sequence that is
    //an exact copy of the sequence without the first character
    SequenceL * rest();
    
private:
    int seqSize; //stores the number of characters in the sequence
    Node * head; //pointer to the first Node in linked list that
                 //stores the sequence
    
    //the copy function makes a copy of a linked list and returns
    //a pointer to its head. It is slightly different depending
    //on whether it's called for rest of from concatenate.
    //See function comments in the .cpp file
    Node * copy(SequenceL *seqptr,string function);
};
