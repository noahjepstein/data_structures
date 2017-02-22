#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector.cpp -- compare three different collision solutions
//
// your job: code the insert functions
//  our job: run the three insert functions and report results
//

// constructor
Hector::Hector()
{
	for(int i = 0; i < TSIZE; i++)
	{
		cheneyTable[i] = NULL;
		linnyTable[i] = SENTINEL;
		doublesTable[i] = SENTINEL;
	}
}


// linear probing
//
//  returns number of collisions before finding a spot
//
int Hector::linny(int value)
{
	int attempt = 0;
	int index;
	bool found = false;
	while(!found)
	{
		index = (3*value + 7 + attempt) % 17;

		if (linnyTable[index] == -1) {
			found = true; 
			linnyTable[index] = value;
		} else {
			attempt++;
		}
	}
	return attempt;
}




// double hashing using a second function
//  
//  returns number of collisions before finding a spot
//
int Hector::doubles(int value)
{

	int attempt = 0;
	int index;
	bool found = false;
	int jump = 13 - (value % 13);

	index = (3*value + 7) % 17; //initial index

	while (!found) {

		if (doublesTable[index] == -1) {
			found = true;
			doublesTable[index] = value;
		
		} else {
			attempt++;
		}

		index = (3*value + 7 + jump * attempt) % 17;
	}
	return attempt;
}



// chained hashing -- each spot in table is a linked list 
//
//  returns number of items in that spot before insertion
//
int Hector::cheney(int value)
{
	int index; 
	int length = 1;

	index = (3*value + 7) % 17; //initial index

	if (cheneyTable[index] == NULL) {
			
		//start new list at index
		cheneyTable[index] = new Node;
		cheneyTable[index]->key = value;
		cheneyTable[index]->next = NULL;
		return 0;
	
	} else {
		
		Node* iter = cheneyTable[index];
		
		while (iter->next != NULL) {
			iter = iter->next;
			length++;
		}
		iter->next = new Node;
		iter->next->key = value;
		iter->next->next = NULL;
	}
	return length;
}




// print the hash tables
void Hector::print()
{
	for(int i=0; i < TSIZE; i++)
	{
		cout << linnyTable[i] << " ";
		
	}
	
	cout << endl;
	
	for(int i=0; i < TSIZE; i++)
	{
		cout << doublesTable[i] << " ";
		
	}
	cout << endl;
	
	Node* iter = NULL;
	for(int i=0; i < TSIZE; i++)
	{
		iter = cheneyTable[i];
		cout << " [";
		while(iter != NULL)
		{
			cout << iter->key << " ";
			iter = iter->next;
		}
		cout << "]";
	}
	cout << endl;
}
