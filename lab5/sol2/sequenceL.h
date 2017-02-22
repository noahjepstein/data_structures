#ifndef SEQUENCEL_H
#define SEQUENCEL_H
#include <cstdlib>
#include <iostream>

using namespace std;

typedef char ElementType;

struct nodeType
{
    ElementType data;
    nodeType *link;
};


class SequenceL
{

public:

    SequenceL();

    SequenceL(ElementType X);

    bool isEmpty();

    int size();

    void concatenate(SequenceL *seq2);

    ElementType first();

    void print();

    SequenceL* rest(); 

private:

    nodeType *head;
	
    void insert(ElementType C);

};

#endif
