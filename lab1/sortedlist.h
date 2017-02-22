
#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
};


class SortedList
{

  public:
    
    SortedList();

    SortedList(int x, int y, int z);

    void print();

    bool isEmpty();

    int getSize();

    void insert(int v);

    
  private:
    int size;
    Node* head;

};






