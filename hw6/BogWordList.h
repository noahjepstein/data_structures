//-----------------------------------------------------------------------------
// Filename: BogWordList.h
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/3/2013
//
// Description: Defines a BogWordList.
//-----------------------------------------------------------------------------

#ifndef BOGWORDLIST_H
#define BOGWORDLIST_H

using namespace std;

struct BogLett
{
	char c;
	int row;
	int col;
};

struct BogWord
{
	int numLetts;
	int capacity;
	BogLett* letts;

	BogWord& operator= (const BogWord &original)
	{
		if (&original != this) {

			numLetts = original.numLetts;
			capacity = original.capacity;
			letts = new BogLett [capacity];

			for (int i = 0; i < numLetts; i++) {
				letts[i] = original.letts[i];
			}
		}
		return *this;
	}
};

struct BogWordList
{
	int numWords;
	int capacity;
	BogWord* words;
};

struct adjLett
{
	char c; 		//letter value
	int i;  		//index
	bool mark; 		//whether or not it's been visited
	adjLett* next;  //next in list of adjacencies
};

#endif
