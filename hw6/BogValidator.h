//-----------------------------------------------------------------------------
// Filename: BogValidator.h
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Header file of Boggle board validator. Heavily uses solver
//				and dictionary data structures for board solution and solution
//				word storage and retrieval. The solver does all the
//				heavy lifting. The dictionary stores the solutions as simple
//				strings for quick retrieval when checking for validation.
//				Prints solutions in the below format:
//															OK (valid word)
//															NO (invalid word)
//-----------------------------------------------------------------------------

#ifndef BOGVALIDATOR_H
#define BOGVALIDATOR_H

#include "dictionary.h"
#include "BogSolver.h"
#include "BogWordList.h"


class BogValidator
{

public: 

	BogValidator(); 						// constructor

	~BogValidator();						// destructor

	bool readDict();						// read in a dictionary

	bool readBoard();						// read in a board

	bool isValid(string s);					// validates one word

	void checkWords();						// validates cin

private:

    //gets the solutions for the boggle board and inserts them into a trie
	void getSolutions();				    

	Dictionary dict;						// it has a widdle dictionary

	BogSolver* BS; 						    //validator has a solver.

	BogWordList* sols;						//solutions to the boggle board

	Dictionary* solTrie;					//trie to store solution words

	bool solved;							//has the board been solved yet?
};

#endif 
