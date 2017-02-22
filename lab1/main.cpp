#include "sortedlist.h"
#include <iostream>
using namespace std;


int main()
{
    
    //first test the print function
    //create a sequence using the overloaded
    //constructor and then print it.
    
    SortedList sl1(50, 12, 33);
    sl1.print();
    
    
    //comment this return 0 out after
    //you have succeeded with the print
    //function
    
    //return 0;
    
    //now try insert into an empty list
    //and test it by printing it.
    SortedList sl2;
    sl2.insert(4);
    sl2.print();
    
    //after you can do one element alone
    //remove this return
    
    
    //now try other cases, will use the linked
    //list of size three and insert something into
    //every loaction
    
    //First test insert at front
    sl1.insert(6);
    sl1.print();
    
    //Second try the middle a couple places
    sl1.insert(7);
    sl1.insert(44);
    sl1.print();
    
    
    //finally try the last position
    sl1.insert(99);
    sl1.print();
    
    
    return 0;
}