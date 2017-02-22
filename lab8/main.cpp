#include "node.h"
#include "ll.h"
#include <iostream>

using namespace std;

int main()
{
	// Make an array to feed into the first linked list
	// Uses overloaded constructor to make a list
	
	int arr1[10] = {3, 6, 10, 13, 28, 44, 76, 95, 100, 295};
	int size1 = 10;

	LL link1(arr1, size1);	
        LL link1copy(link1);
        LL link1copy2(link1);

	// Make a second array to feed into the second linked list
	// Uses overloaded constructor to make a list
	
	int arr2[8] = {1, 7, 13, 30, 52, 98, 307, 310};
	int size2 = 8;
	
	LL link2(arr2, size2);
	
	// The third linked list will be empty
	// Uses default constructor to make an empty list

	LL empty;

	cout << "List 1 contains: " << endl;
	link1.print();
	cout << "List 2 contains: " << endl;
	link2.print();
	cout << "List 3 contains: " << endl;
	empty.print();

	cout << "Merging link1 and link2 gives: " << endl;
	link1.merge(link2);
	link1.print();
	cout << "Output should be: " << endl;
	cout << "1 3 6 7 10 13 13 28 30 44 52 76 95 98 100 295 307 310" << endl;
	cout << endl;

	cout << "Merging link2 and link1 gives: " << endl;
	link2.merge(link1copy);
	link2.print();
	cout << "Output should be: " << endl;
	cout << "1 3 6 7 10 13 13 28 30 44 52 76 95 98 100 295 307 310" << endl;
	cout << endl;

	cout << "Merging link1 and the empty list gives: " << endl;
	link1copy2.merge(empty);
	link1copy2.print();
	cout << "Output should be: " << endl;
	cout << "3 6 10 13 28 44 76 95 100 295 "<< endl;


	return 0;	
}
