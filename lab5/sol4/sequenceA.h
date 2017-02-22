//      Tufts University
//      Document Created 9/5/13
//      Sequence With Dynamic Array .h File - sequenceA.h
//      COMP15: Data Structures

//******************************************************************************

#ifndef sequences_sequenceA_h
#define sequences_sequenceA_h
#include <iostream>
#include <cstdlib>
using namespace std;

//******************************************************************************
// housekeeping: making constants and setting typedef

const int INIT_SIZE = 10;
typedef char ElementType;

//******************************************************************************
// class description

class SequenceA
{
public:
        
    SequenceA();
    SequenceA(ElementType data);
    // ^^^ constructors
    
    bool isEmpty();
    // ^^^ takes in nothing, returns boolean specifying if sequence is empty
        
    int size();
    // ^^^ returns integer referring to the numbers of chars in the sequence
        
    void concatenate(SequenceA *newData);
    // ^^^ needs to take a pointer in
    
    ElementType first();
    // ^^^ returns first element of sequence
        
    SequenceA * rest();
    // ^^^ returns a pointer to a sequence that is equivalent to the original
    //     except  the first character is no longer part of the sequence */
        
    void print();
    // ^^^ prints out the sequence to the screen
    
private:
    
    int currentSize;
    // ^^^ maintains the current size of the sequence
    //     for no-argument constructor, set to 0
    //     for argument constructor, set to 1
        
    int currentCapacity;
    // ^^^ will be assigned to an INIT_SIZE
    //     updated to 2*currentCapacity whenever more space is needed
    
    ElementType * array_pointer;
    // ^^^ pointer to dynamic array
    //     sequence = new ElementType[INIT_SIZE]
    //     ^^^ REMEMBER THIS
        
    void expand_array();
    // ^^^ function expands array from currentCapacity to 2*currentCapacity
    //     remember to update currentSize...if that wasn't obvious
    
    void quit(string error);
    // ^^^ function quits with string as error
    
                
};

//******************************************************************************

#endif