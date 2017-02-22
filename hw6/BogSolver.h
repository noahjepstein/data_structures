//-----------------------------------------------------------------------------
// Filename: BogSolver.h
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Header file for Boggle board solver.
// 				Has all required public functions. 
//				Has a collection of private data members: various lists of 
//				words and larger, more complex data structures, like adjacency
//				lists, bogwordlists, and dictionaries. 
//				Has a collection of functions for reading in a boggle board 
//				and populating the associated adjacency list.
//				Has a collection of functions for solving the boggle board
//				and storing all solved words, as well as keeping track of their
//				locations on the boggle board.
//				Features a few testing functions and miscellaneous helpers.
//-----------------------------------------------------------------------------

#ifndef BOGSOLVER_H
#define BOGSOLVER_H

#include <iostream>
#include "BogWordList.h"
#include "dictionary.h"

using namespace std;


class BogSolver
{

public:

	BogSolver();					//constructor

	~BogSolver();					//destructor for ALL

	bool readDict();				//reads in the dictionary of ref words

	bool readBoard();				//reads in the boggle board to make adjList

	bool solve(); 				    //search board for words in dict

	int numWords(); 			    //returns number of words found

	int numWords(int len);		    //returns nWords of length len

	BogWordList* getWords(); 		//returns all words found

	BogWordList* getWords(int len);	//returns all words of length len

	void printWords();              //prints all words in HBF

	void printWords(int len);		//prints len-length words in HBF

	void listWords();				//prints just text, no coordinates

	void listWords(int len);		//prints just text, no coords of length len


private:

	Dictionary dict; 		//dictionary for word checking

	Dictionary* foundList;  //list of found words for quick retrieval

	BogWordList* BWL; 		//for post-sol data storage and HBF/STD printing

	adjLett* adjList; 		//adjList is a dyn array of nLetts adjLetts

	BogWord** looseEnds;    //used to keep track of unused nodes


	int bHeight; 			//height of board

	int bWidth; 		    //width of board

	int nLetters; 			//total number of letters in the bog board
	
	bool success; 			//shared variable for tracking success of  funcs



	//BOARD READING FUNCTIONS--------------------------------------------------

	//puts letters into adjacency list
	void insertLetters(); 
	
	//adds the linked list of adjacent letters to each letter
	bool populateAdjacencies();  

	void addTop(int i, int j);  //adds adjacencies above letter i to adjlist

	void addMid(int i, int j);  //adds adjacencies on same row as lett to list

	void addBot(int i, int j);  //adds adjacencies below lett i to adjList

	bool onBoard(int i, int j); //checks if j is on board in reference to i

	adjLett* startAdjList(int i);  //starts the adjlist for a letter i

	void addToAdjList(int i, int loc); //adds adjacency to adjList for ith lett

	bool outOfBounds(int i, int j); //true if an adjacent int j is off board

	//-------------------------------------------------------------------------



	//SOLVING FUNCTIONS--------------------------------------------------------

	//recursive function for finding words in the boggle board. 
	void wordSearch(int i, string word, BogWord* bW);


	//makes a new bogword with data from the ith adjList letter
	BogWord* makeBogWord(int i);

	//bogword is array of bogletts. adds ith lett to bogword
	BogWord* addLett(int i, BogWord* bWord);

	//expands the bogword dynamic array
	BogWord* expandBogWord(BogWord* bWord);

	//adds a bog word to the bogwordlist. used when new words are found
	void addToBWL(BogWord* bWord);

	//expands the BogWordList so it will fit mroe words!
	BogWordList* expandBWL(BogWordList* bwList);

	void addToFoundList(string word); //adds a word to list of words in the board

	//determines if a string is a word (toAdd enables Q-checking)
	bool isWord(string word, char toAdd);

	//determines if string's a prefix  (toAdd enables Q-checking)
	bool isPrefix(string word, char toAdd); 

	bool alreadyFound(string word); //if word is already found in the board	

	//------------------------------------------------------------------------



	//INTERNAL TESTING FUNCTIONS-----------------------------------------------

	//prints the adjacency list
	//function determines whether the board reading functions are working
	void printAdjList();

	//recursive implementation of linked list deletion function
	void delete_recursive(adjLett* node);

};

#endif 
