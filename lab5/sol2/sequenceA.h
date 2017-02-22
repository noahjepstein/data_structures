#ifndef SEQUENCEA_H
#define SEQUENCEA_H
#include <cstdlib>
#include <iostream>

using namespace std;

typedef char ElementType;
const int INITSIZE = 10;


class SequenceA
{
public:
    SequenceA();  

    SequenceA(ElementType X); 

    bool isEmpty();

    int size(); 
	    
    void concatenate(SequenceA *seq2);

    ElementType first();

    void print();

    SequenceA* rest();

private:
    ElementType* str;

    int strsize;
};

#endif
