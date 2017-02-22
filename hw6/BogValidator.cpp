//-----------------------------------------------------------------------------
// Filename: BogValidator.cpp
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Implementation of Boggle board validator. Heavily uses solver
//				and dictionary data structures for board solution and solution
//				word storage and retrieval. The solver does all the
//				heavy lifting. The dictionary stores the solutions as simple
//				strings for quick retrieval when checking for validation.
//				Prints solutions in the below format:
//															OK (valid word)
//															NO (invalid word)
//-----------------------------------------------------------------------------

#include "BogValidator.h"


//constructor for the bogvalidator. 
//creates a solver which it will use to create solutions.
//uses a trie to store all solution words for fast loookup. 
//trie comes from reused Dictionary data structore.
//hasn't been solved yet.
//featurse a check for proper memory allocation
BogValidator::BogValidator()
{
	BS = new BogSolver;
	solTrie = new Dictionary;

	solved = false;

	// check memory allocation
	if ((BS == NULL) || (solTrie == NULL)) {
		cout << "memory allocation failure" << endl;
		exit(1);
	}
}


//destructor for the bogvalidator
//deletes all the words in the solution bogwordlist individually, 
//letter by letter. 
//deletes the solution list, deletes the solution trie,
//and deletes the solver.
BogValidator::~BogValidator()
{
	for (int i = 0; i < sols->capacity; i++) {

		delete [] sols->words[i].letts;//deletes each letter in the words
	}
	delete [] sols; //deletes the array that used to hold the words
	delete solTrie;
	delete BS;
}


//lets the solver do all the work!
bool BogValidator::readDict()
{
	return BS->readDict();
}


//lets the solver do all the work!
bool BogValidator::readBoard()
{
	return BS->readBoard();
}


//if the string s is a word, it checks it in the solTrie.
//this allows us to check long, long list of words while still
//remaining time efficient.
bool BogValidator::isValid(string s)
{
	//checks to see if the board has been solved first
	if (!solved) {
		BS->solve();
		solved = true;
	}
	if (solTrie->isWord(s)) {
		return true;
	} else {
		return false;
	}
}


//simple checker for all words. uses the (public) isValid function. 
//reads in words, and checks them individually. prints yes or no to 
//tell whether the word is valid or not. 
void BogValidator::checkWords()
{
	string word;
	while (!cin.eof()) {

		cin >> word;

		if (isValid(word)) {
			cout << "OK " << word << endl;
		} else {
			cout << "NO " << word << endl;
		}
	}
}


//gets the solution list for the boggle board from the solver.
//it puts all the words in teh solution list into the soltrie 
//it will then use the soltrie for validation lookups. 
void BogValidator::getSolutions()
{
	string word;
	int wordLength;
	sols = BS->getWords();
	for (int i = 0; i < sols->numWords; i++) {
		
		word = "";
		wordLength = sols->words[i].numLetts;

		for (int j = 0; j < wordLength; j++) {
			word.append(1, sols->words[i].letts[j].c);
		}
		solTrie->insert(word);
	}
}
