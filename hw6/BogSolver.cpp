//-----------------------------------------------------------------------------
// Filename: BogSolver.h
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Implementation for Boggle board solver.
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


#include "BogSolver.h"

const int SENTINEL = -1;
const int INIT_NWORDS = 500;
const int INIT_WORDLEN = 40;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//						CONSTRUCTOR/DESTRUCTOR FUNCTIONS
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//just a couple things to initialize
//and a couple to make NULL
BogSolver::BogSolver()
{
	adjList = NULL;
	foundList = new Dictionary;
	success = false;
	
	BWL = new BogWordList;
	BWL->numWords = 0;
	BWL->words = new (nothrow) BogWord [INIT_NWORDS];
	
	if ((BWL->words == NULL) || (foundList == NULL)) {
		
		cout << "memory allocation failure at construction" << endl;
		exit(1);
	
	} else {
		BWL->capacity = INIT_NWORDS;
	}
}


//remember all that memory we allocated?
//IT ALL HAS TO GO AWAY
BogSolver::~BogSolver()
{
	for (int i = 0; i < BWL->capacity; i++) {

		delete [] BWL->words[i].letts;//deletes each letter in the words
	}

	delete [] BWL; //deletes the array that used to hold the words

	//recursively deletes the adjList
	for (int i = 0; i < nLetters; i++) {
		delete_recursive(adjList[i].next);
		delete [] looseEnds[i]->letts;
	}

	delete [] looseEnds; //like in the mob
	delete [] adjList;	 //deletes the adjacency list
	delete foundList;	 //deletes the foundList.
}

//walks down a linked list of adjacencies deleting as it goes
//used rather than while loop and two iters...etc.
void BogSolver::delete_recursive(adjLett* node)
{
	if(node != NULL) {
		delete_recursive(node->next);
	}

	delete node;
}




//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//							DATA READING FUNCTIONS
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


//reads in a list of words that count as valid boggle words when played
//returns false for memory allocation errors.
bool BogSolver::readDict()
{
	string input;
	success = true; //assume we start w/ memory available until otherwise

	while (true) { //will read in data until sentinel value. then loop breaks.

		cin >> input; 

		if (input == ".") { //sentinel value for end of dictionary input
			break;
		
		} else {	
			success = dict.insert(input);
		}
	}
	return success;
}


//reads in a new boggle board of bHeight and bWidth 
//containing nLetters. populates an adjacency list, 
//each element of which has a character (letter), an index, 
//a mark to determine visitation, and a list of adjacent letters
bool BogSolver::readBoard()
{
	cin >> bHeight >> bWidth;
	nLetters = bHeight * bWidth;

	adjList = new (nothrow) adjLett [nLetters];

	if (adjList == NULL) {
		success = false;
		cout << "memory allocation failure" << endl;
	}

	insertLetters();
	success = populateAdjacencies();
	//printAdjList(); //for testing right now

	return success;
}



//puts all letters consecutively in the adjacency list. 
//turns the 2D boggle board into a 1D dynamic array of letters, 
//each letter having a character, an index, a mark to determine 
//whether or not it's been included in a word (while solving), 
//and a linked list of letters that are adjacent to the letter.
void BogSolver::insertLetters()
{
	string row;

	for (int i = 0; i < bHeight; i++) {
		
		cin >> row;

		for (int j = 0; j < bWidth; j++) {
			
			adjList[i * bWidth + j].c     = row[j];
			adjList[i * bWidth + j].i     = SENTINEL; //for 1st elem
			adjList[i * bWidth + j].mark  = false;
			adjList[i * bWidth + j].next  = NULL;
		}
	}
}



//adds the linked list of adjacent letters to each letter in the board
//adds adjacencies from top to bottom, left to right. 
//(e.g. top left, middle left, bottom left, top middle, bottom middle, etc...)
//it worked if the last letter has an adjacency list
bool BogSolver::populateAdjacencies()
{
	success = true;
	for (int i = 0; i < nLetters; i++) {

		for (int j = -1; j < 2; j++) {

			addTop(i, j);
			addMid(i, j);
			addBot(i, j);
		}
	}

	//if the adjacency list is completely populated, it worked
	return true;
}



//adds adjacencies on the row above the letter i. 
//i determines the letter, j ranges from -1 to 1 and determines
//whether it inserts the left, middle, or right adjacent letter. 
//can't insert itself as an adjacency
void BogSolver::addTop(int i, int j)
{
	int loc = i + j - bWidth; //above i
	
	if (onBoard(i, loc)) {
	
		if (adjList[i].next == NULL) {
			adjList[i].next = startAdjList(loc); //start new

		} else {
			addToAdjList(i, loc); //add to old
		}
	}
}



//adds adjacencies on the same row as the letter i. 
//i determines the letter, j ranges from -1 to 1 and determines
//whether it inserts the left, or right adjacency. 
//can't insert itself as an adjacency
void BogSolver::addMid(int i, int j)
{
	if (j == 0) {
		return; //don't wanna add yourself doe
	}
	int loc = i + j;

	if (onBoard(i, loc)) {
	
		if (adjList[i].next == NULL) {
			adjList[i].next = startAdjList(loc);

		} else {
			addToAdjList(i, loc);
		}
	}
}



//adds adjacencies on the row below the letter i. 
//i determines the letter, j ranges from -1 to 1 and determines
//whether it inserts the left bottom, middle bottom, or right bottom
void BogSolver::addBot(int i, int j)
{
	int loc = i + j + bWidth; //bottom left to right

	if (onBoard(i, loc)) {
		
		if (adjList[i].next == NULL) {
			adjList[i].next = startAdjList(loc); //start a new one
		
		} else {
			addToAdjList(i, loc); //add to the old one
		}
	}
}



//starts a new adjList[i].next at letter i. making new nodes is fun!
//fills it with the values contained at adjList[i]
adjLett* BogSolver::startAdjList(int i)
{
	//make a new node
	adjLett* adjacency = new (nothrow) adjLett;

	if (adjacency == NULL) {
		
		success = false;
		cout << "memory allocation failure" << endl;
	}


	adjacency->c = adjList[i].c;
	adjacency->i = i;
	adjacency->mark = false;
	adjacency->next = NULL;


	return adjacency; //return its address
}



//adds an adjacency at loc to the adjacency list for i.
//fills with values for adjList[loc]
void BogSolver::addToAdjList(int i, int loc)
{
	adjLett* iter = adjList[i].next; //make iterator
	
	//iterate until you're at end of adjList[i].next
	while ((iter != NULL) && (iter->next != NULL)) {
		iter = iter->next;
	}

	//put a new node there!
	iter->next = new (nothrow) adjLett;
	if (iter->next == NULL) {
		success = false;
		cout << "mem alloc failure" << endl;
	}

	iter->next->c = adjList[loc].c;
	iter->next->i = loc;
	iter->next->mark = false;
	iter->next->next = NULL;
}



//function to determine whether an adacency of index loc 
//is on the board in relation to a letter of index i. 
//for example, for the first letter on the board  w/ (i = 0), 
//the adjacency to its immediate left would be loc = -1, which
//falls off the left edge of the board.
bool BogSolver::onBoard(int i, int loc)
{
	//if location jumps off top or bottom of board
	if ((loc < 0) || (loc >= nLetters)) {
		return false;

	//if location jumps off left side of board	
	} else if ( ((i % bWidth) == 0) 
		     && ((loc % bWidth % (bWidth - 1)) == 0) ) {
		return false;
	
	//if location jumps off right side of board
	} else if ( ((i % bWidth & (bWidth - 1)) == 0) 
		     && (loc % bWidth == 0) ) {
		return false;
	
	} else {
		return true; //loc is adjacent to i
	}
}












//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//							SOLVER FUNCTIONS
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------



//while recursing, the solver needs to keep track of the word being created 
//as a copy (so it's deleted when we go backwards in the recursion). it keeps 
//track of the word as a string, which stays as a copy within the scope of 
//each call of wordsearch.

bool BogSolver::solve()
{
	if (adjList == NULL) {
		return false;
	}

	success = true;
	string word = "";
	BogWord* bW = NULL;

	//loose ends is a list of all BogWords that are created. 
	//even the ones that never become words becuase they're not 
	//valid in the board still need to be deleted. this keeps
	//track of them: they're loose ends.
	looseEnds = new BogWord* [nLetters];

	//check all letters in board to see if there are any words
	//that start with them
	for (int i = 0; i < nLetters; i++) {
		
		bW = makeBogWord(i);
		looseEnds[i] = bW;
		wordSearch(i, word, bW);
	}

	return success;
}



//wordsearch all adjacencies
//mark all visited letters
//add complete words to the list
void BogSolver::wordSearch(int i, string word, BogWord* bW)
{
	if ( (!adjList[i].mark) && isPrefix(word, adjList[i].c) ) {
		adjLett* iter = adjList[i].next;

		while (iter != NULL) {
			
			//recurse on it
			wordSearch(iter->i, word + adjList[i].c, addLett(i, bW));
			
			//mark it as visited
			adjList[i].mark = true;
			
			//if they're words, add them to "found word lists"
			if (isWord(word, adjList[i].c) 
				&& !alreadyFound(word + adjList[i].c)) {

				//cerr << "found word: " << word << endl;
				addToFoundList(word + adjList[i].c);
				addToBWL(addLett(i, bW));
			
			}

			iter = iter->next;
		}
	}

	//these letters are no longer in the word. we remove them as we move back
	//up the stack, removing traces that we've "been here" so that they a) can
	//be used in other words, and b) so that we don't end up with random 
	//additional letters in our BogWord
	adjList[i].mark = false;
	bW->numLetts--;
}


//-------------------------BOGWORDLIST MANIPULATION----------------------------


//done
//makes a new BogWord, complete with malloc checks. 
//first makes the word node that will be included in the BogWordList,
//then makes the letter node that will go inside bogWord's list.
 BogWord* BogSolver::makeBogWord(int i)
 {
 	//make a new word w/ mem alloc check
 	BogWord* toMake = new (nothrow) BogWord;
 	
 	if (toMake == NULL) {
 		success = false;
 		cout << "memory allocation failure" << endl;
 	
 	} else {

	 	//make a letter list for the word, w/ a mem alloc check
	 	toMake->letts = new (nothrow) BogLett [INIT_WORDLEN];
	 	
	 	if (toMake->letts == NULL) {
	 		success = false;
	 		cout << "memory allocation failure" << endl;
	 	
	 	} else {
	 	
		 	toMake->letts[0].c = adjList[i].c;
		 	toMake->letts[0].row = i / bWidth;
		 	toMake->letts[0].col = i % bWidth;
			toMake->numLetts = 1;
		}
	}
 	return toMake;	
}


//done
//adds a letter at adjList index i to the bogword. 
//makes sure not to dereference those pesky null pointers. 
//expands if it needs to. doesn't if it doesn't. 
//if there's no current word, it just makes one. 
BogWord* BogSolver::addLett(int i, BogWord* bWord)
{
	if (bWord != NULL) {
		
		if (bWord->numLetts >= bWord->capacity) {
			bWord = expandBogWord(bWord);
		}
		
		//put all the data in the new letter of the new word
		bWord->letts[bWord->numLetts].c = adjList[i].c;
		bWord->letts[bWord->numLetts].row = i / bWidth;
		bWord->letts[bWord->numLetts].col = i % bWidth;
		bWord->numLetts++;

	} else {
		
		//bWord is null so start the word instead of adding to it
		bWord = makeBogWord(i);
	}
	return bWord;
}


//done
//expands the bogword dynamic array. standard expansion algorithm.
BogWord* BogSolver::expandBogWord(BogWord* bWord)
{
	BogLett* temp = new BogLett [bWord->capacity * 2];
	
	for (int i = 0; i < bWord->numLetts; i++) {
		temp[i] = bWord->letts[i];
	}

	//delete old, in w/ new
	delete [] bWord->letts;
	bWord->letts = temp;
	bWord->capacity *= 2;

	return bWord;
}



//done
//if you're adding a q to the word, it adds a u to the q. 
//Q can't exist in the boggle board without a u. 
bool BogSolver::isWord(string word, char toAdd)
{
	string s = "";
	s.append(1, toAdd);

	if (s == "Q") {
		s += 'U'; //adds u to the new char
	}

	if (word == "Q") {
		word +=  "U"; //adds u to the original word if 
					  //q is its only letter
	}

	word += s;

	//words have to be 3+ in length and valid in the dict
	return (dict.isWord(word) && (word.length() > 2)); 
}



//done
//determines if s is a prefix of a word (if its a word, also a prefix)
//adds a u to every q
bool BogSolver::isPrefix(string str, char toAdd)
{
	string s = "";
	s.append(1, toAdd); //appends toADd to s once

	if (s == "Q") {
		s += 'U'; //adds u to every q
	}

	if (str == "Q") {
		str +=  "U"; //adds u to every q
	}

	str += s;
	return dict.isPrefix(str);
}


//inserts a word into our list for "foundwords"
//foundList is a dictionary because it makes retrieval for foundword
//checking very quick, and we already have the data structure so it's
//very easy to implement and use as a storage and checking medium
void BogSolver::addToFoundList(string word)
{
	foundList->insert(word);
}


//adds a new word to the bogowrdlist. only takes in bogword format
//words. if necessary, expands the list. otherwise, it just adds a word
//uses the assignmetn overload for bogwords.
void BogSolver::addToBWL(BogWord* bWord)
{
	if (BWL->numWords >= BWL->capacity) {
		BWL = expandBWL(BWL);
	}

	BWL->words[BWL->numWords] = *bWord; //calls assignment overload
	BWL->numWords++;
}


//expands a bogwordlist using standard dynamic array expansion
//algorithm. expands by factor of 2. uses assignment operator overload
//for bogwords.
BogWordList* BogSolver::expandBWL(BogWordList* bwList)
{
	BogWord* temp = new BogWord [bwList->capacity * 2];

	for (int i = 0; i < bwList->numWords; i++) {
		temp[i] = bwList->words[i];
	}

	delete [] bwList->words;
	bwList->words = temp;
	bwList->capacity *= 2;

	//standard expansion algorithm
	return bwList;
}



//done
//determines if a word has already been found in the board
//using the foundlist for quick retrieval
bool BogSolver::alreadyFound(string word)
{
	return foundList->isWord(word);
}



//-----------------------------------------------------------------------------
//								JUST SOME FUNCTIONS
//-----------------------------------------------------------------------------


//stored as data member in the BWL
int BogSolver::numWords()
{
	return BWL->numWords; //one liner!
}


//goes through all the words and incrememnts a counter
//if the length of the word in teh list is equal to the
//length parameter.
int BogSolver::numWords(int len)
{
	int n = 0;

	for (int i = 0; i < BWL->numWords; i++) {
		
		if (BWL->words[i].numLetts == len) {
			n++;
		}
	}

	return n;
}


// returns all the words in the board
// makes a complete, in depth copy of the solver's bogwordlist.
// uses all the same data as the original. 
BogWordList* BogSolver::getWords()
{
	BogWordList* copy = new BogWordList;

	copy->numWords = BWL->numWords;
	copy->capacity = BWL->capacity;
	copy->words = new BogWord [copy->capacity];

	for (int i = 0; i < copy->numWords; i++) {
		copy->words[i] = BWL->words[i];
	}

	return copy;
}



// returns all words in the board of length len
//makes a completely new bogwordlist. 
//fills w/ data, and fills wordlist by keeping two separate counters
//for locations in respective arrays.
//(an array w/ all length words will almost always be longer than one
//of one specific length). 
BogWordList* BogSolver::getWords(int len)
{
	BogWordList* copy = new (nothrow) BogWordList;
	int j = 0;

	if (copy == NULL) {
		cout << "mem alloc fail" << endl;
		exit(1);
	}

	copy->numWords = numWords(len);
	copy->capacity = copy->numWords * 2; //so we have space, but not nWords spa
	copy->words = new BogWord [copy->capacity];
	
	if (copy->words == NULL) {
		cout << "mem alloc fail" << endl;
		exit(1);
	}

	for (int i = 0; i < BWL->numWords; i++) {
		
		if (BWL->words[i].numLetts == len) {
			copy->words[j] = BWL->words[i];
			j++;
		}
	}

	return copy;
}



// prints all the words in the board w/ coordinates
// in specified HBF format as follows
// < char row col char row col char row col > 
// with row and col indexing starting at zero.
void BogSolver::printWords()
{
	for (int i = 0; i < 
		BWL->numWords; i++) {
		
		cout << "< ";
		
		for (int j = 0; j < BWL->words[i].numLetts; j++) {

			//just prints out the word with all its 
			//rows and cols in HBF format
			cout << BWL->words[i].letts[j].c
				 << " "
				 << 
				 BWL->words[i].letts[j].row
				 << " "
				 << 
				 BWL->words[i].letts[j].col
				 << " ";
		}

		cout << ">" << endl;
	}
}


// prints all words in the board of length len w/ coordinates
// prints all the words in the board w/ coordinates
// in specified HBF format as follows
// < char row col char row col char row col > 
// with row and col indexing starting at zero.
void BogSolver::printWords(int len)
{
	for (int i = 0; i < 
		BWL->numWords; i++) {
	
		if (BWL->words[i].numLetts == len) {

			cout << "< ";
			for (int j = 0; j < BWL->words[i].numLetts; j++) {

				//just prints out the word and all its 
				//letters in special HBF format 
				//except that it only does words of len len
				cout << BWL->words[i].letts[j].c
					 << " "
					 << 
					 BWL->words[i].letts[j].row
					 << " "
					 << 
					 BWL->words[i].letts[j].col
					 << " ";
			}
			cout << ">" << endl;	
		}
	}
}


// lists (w/o coordinates) all words in the board
// goes to each word in BWL, printing it letter by letter
void BogSolver::listWords()
{
	for (int i = 0; i < 
		BWL->numWords; i++) {
				
		for (int j = 0; j < 
			BWL->words[i].numLetts; j++) {

			//output each letter individually
			cout << BWL->words[i].letts[j].c;
		}

		cout << endl;
	}	
}


// lists (w/o coordinates) all words in the board of lenth len
//goes through the entire bogwordlist of words, printing each word
//letter by letter.
void BogSolver::listWords(int len)
{
	for (int i = 0; i < 
		BWL->numWords; i++) {
	
		if (BWL->words[i].numLetts == len) {

			for (int j = 0; j < 
				BWL->words[i].numLetts; j++) {

				cout << 
			BWL->words[i].letts[j].c;
			}
			cout << endl;	
		}
	}	
}








//-----------------------------------------------------------------------------
//						INTERNAL TEST FUNCTIONS
//-----------------------------------------------------------------------------


//printAdjlist is only used for internal testing when creating the program.
//this function has nothing to do with the normal operation of the 
//program and is only used to check that an adjacency list is 
//populated correcetly. 
void BogSolver::printAdjList()
{
	adjLett* iter;
	for (int i = 0; i < nLetters; i++) {
		
		cout << adjList[i].c << ": ";
		iter = adjList[i].next;
		
		while (iter != NULL) {
			cout << iter->c;
			iter = iter->next;
		}
		cout << endl;
	}
}


