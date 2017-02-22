// sequenceA.h
// Specifies a Sequence class implemented
// with a dynamic array
// due 9/17

#ifndef SEQUENCEA_H
#define SEQUENCEA_H

// #include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

// the type of element to be stored in 
// Sequence class
typedef char ElementType;

// initial size of dynamic array
const int INIT_SIZE = 1;

// growth factor for dynamic array
const int GROWTH_FACTOR = 2;

// Sequence class
class SequenceA
{
public:
    // Constructors
    // Default
    SequenceA();

    // Overload
    SequenceA(const ElementType entry);

    // Modification
    // Adds the elements of an imput Sequence to this
    bool concatenate(const SequenceA* toCopy);

    // Constant
    // Returns if the Sequence is empty
    bool isEmpty() const;

    // Returns the size of the Sequence
    int size() const;

    // Returns a copy of the first element in the Sequence
    ElementType first() const;

    // Returns a pointer to a new Sequence containing
    // all the members of this class, minus the first
    // element
    SequenceA* rest() const;

    // Prints the elements stored in this class
    bool print() const;

private:
    // Inserts an element at the end of the Sequence
    bool insert(const ElementType entry);

    // Expands the dynamic array of the Sequence
    bool expand();

    // Dynamic array of ElementTypes
    ElementType* data;

    // Tracks the size of the Sequence
    int ElementTypeNo;

    // Tracks the capacity of the dynamic array
    int capacity;
};

#endif
