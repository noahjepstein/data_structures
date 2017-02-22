/* sandwichList.h
 * Comp 15 
 * Spring 2013 
 * Lab 3
 */

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;
const int INITIAL_SIZE = 5;


struct Order {
  string sandwich;
  string customerName;
  int orderNbr;
  bool fries;
};


class SandwichList{

public:

  SandwichList();

    //Interface for queue
  Order getNext();
  void add(const Order& sandwich);
  bool isEmpty();
  int size();	

    //test function if you like
    //not the best design, shouldn't be queues
    //job to print an order
  void printOrder(Order s);

private:

    //capacity is size of array, not amount stored in list
  int capacity;
  Order* orders;
  void expandList();

    //use front and back to figure out how much is in the list
  int front;
  int back;	
};

#endif
