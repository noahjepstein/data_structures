#include <iostream>
using namespace std;
typedef char ElementType;

class SequenceA
{
public:
    //This is the default constructor
    //and it creates an empty sequence
    SequenceA();
    
    //This is a constructor that takes
    //a char, creates an empty sequence,
    //and sets the char as the first element
    SequenceA(ElementType data);
    
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
    void concatenate(SequenceA * seqptr);
    
    //print will go through the sequence
    //and print every character leaving spaces in between
    void print();
    
    //first returns the first character in the sequence
    //NOTE: The program will exit if first is passed
    //an empty sequence
    ElementType first();
    
    //rest returns a pointer to a new sequence that is
    //an exact copy of the sequence without the first character
    SequenceA * rest();
    
private:
    int seqSize;    //stores the number of characters in the sequence
    int arraySize;  //stores the number of spaces in the dynamic array
                    //that is available for use
    ElementType * seqList; //this is the pointer to the sequence
    
};


