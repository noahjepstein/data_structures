#ifndef SEQUENCEL_H
#define SEQUENCEL_H

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


typedef char ElementType;


struct Node
{
    ElementType data;
    Node* next;
};


class SequenceL
{
public:

    SequenceL();

    SequenceL(const ElementType entry);
    
    bool concatenate(const SequenceL* toAdd);

    bool isEmpty() const;


    bool print() const;

    int size() const;

    ElementType first() const;

    SequenceL* rest() const;
    
private:

    bool insert(const ElementType entry);
    
    Node* head;

    Node* tail;

    int ElementTypeNo;
};

#endif
