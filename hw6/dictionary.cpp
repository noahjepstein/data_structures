//-----------------------------------------------------------------------------
// Filename: dictionary.cpp
// Author:   Noah J. Epstein
// Date:     11/22/2013
// Rev-Date: 11/22/2013
//																			
// Description: Implementation of a dictionary data structure, 
// implemented using a trie. Includes a constructor, destructor (recursive) 
// and destructor tag func. 
//                                                                             
// 
//-----------------------------------------------------------------------------

#include "dictionary.h"


//-----------------------------------------------------------------------------
//							CONSTRUCTOR/DESTRUCTOR
//-----------------------------------------------------------------------------

//default constructor for the dictionary class. calls makeNode that handles 
//memory allocation 
Dictionary::Dictionary()
{
	head = makeNode();
	if (head == NULL) {
		exit(1);
	}
	head->value = '\0'; //value for empty char
}

//destructor just calls the recursive implementation of the same. 
Dictionary::~Dictionary()
{
	delete_recursive(head);
}


//recursive method for destructor to delete entire dictionary. 
//cannot handle length of strings longer than 2^17 characters.
void Dictionary::delete_recursive(Node* root)
{
	for (int i = 0; i < ALPHA_SIZE && root != NULL; i++){
		if (root->next[i] != NULL) {
			delete_recursive(root->next[i]);
		}
	}
	delete root;
	root = NULL;
}


//-----------------------------------------------------------------------------
//								GENERAL PURPOSE FUNCTIONS
//-----------------------------------------------------------------------------


//function to "clean" strings
//takes out all non-alphabetic characters and converts all uppercase characters
//to lowercase characters. a completely non-alphabetic string would as such
//become the empty string as all non-alpha characters are removed.
string Dictionary::clean(string s)
{
	int len = s.length();
	string clean_s = ""; //empty str into which we put "cleaned" chars

	for (int i = 0; i < len; i++){
		
		if (isalpha(s[i])) {
			//non alphas are dropped.
			//uppercase chars are lowered.
			clean_s += tolower(s[i]); 
		}
	}
	return clean_s;	
}


//returns the index of c's position in the alphabet.
//i.e. 'a' is at index 0, z at index 25...etc. 
int Dictionary::charToInt(char c)
{
	return (c - 'a');
}


//determines whether the string is the empty string or otherwise
bool Dictionary::isEmptyString(string s)
{
	return (s == "");
}


//-----------------------------------------------------------------------------
//						IS-PREFIX/IS-WORD FUNCTIONS
//-----------------------------------------------------------------------------


//is prefix determines whether or not a string is a prefix of other words. 
//if it's an empty string, it's a prefix of all words.
//if it's not empty but doesn't end in a leaf, then it's a prefix.
bool Dictionary::isPrefix(string s)
{
	s = clean(s); 

	//empty strings are prefixes of ALL WORDS
	//except when empty dic!
	if ((isEmptyString(s)) && (!isLeaf(head))) { 
		return true;
	
	} else if (isWord(s)) {
		return true;

    } else {
		return checkPrefix(s); //if not empty, check if it's a real prefix...
	}
}


//check prefix is a helper function for isPrefix.
//iterates through the structure using a for loop, going letter by letter.
//if you reach an end without getting to the end of the word, it's not a 
//prefix. if you reach the end of the word and you're at a leaf, the 
//string is a word, not a prefix. otherwise, it's a prefix! 
bool Dictionary::checkPrefix(string s)
{
	unsigned int len = s.length();
	Node* iter = head;
	int j;

	for (unsigned int i = 0; i < len; i++) {

		j = charToInt(s[i]); //alpha index of character

		if (iter->next[j] != NULL) {
			iter = iter->next[j]; 
			//if you get to the end of the word and it's not a leaf
			//then the string is a prefix
			if (i == (len - 1) && !isLeaf(iter)) {
				return true;
			}
		} else {
			return false;
		}
	}
	return false; //yo, you got through the list and it was a leaf.
}


//isWord is a function to determine whether a string is a word
//in our dictionary. it cleans the word first. if the string is an empty
//string and the empty str is a word, we return true;
//otherwise, a helper is called.
bool Dictionary::isWord(string s)
{
	s = clean(s);		

	if (isEmptyString(s) && head->isEnd) {
		return true; 
	} else {
		return checkNonEmptyWord(s);
	}
}


//checks if a node is a leaf. nodes are leaves if and only if they 
//have no "next letters" attached to them. 
bool Dictionary::isLeaf(Node* node)
{
	if (node != NULL){
		
		for (int i = 0; i < ALPHA_SIZE; i++) {
			//if your words continue on past this letter
			//then this letter is not a leaf
			if (node->next[i] != NULL) {
				return false;
			}
		}
	} else {
		exit(1); //you can't check if a null node is a leaf
	}
	return true; //passed all the tests!
}


//check nonempty word is a helper function for isWord. 
//only takes in clean words. no dirty words!
bool Dictionary::checkNonEmptyWord(string s)
{	
	unsigned int len = s.length();
	Node* iter = head;
	int j;

	for (unsigned int i = 0; i < len; i++) {
		
		j = charToInt(s[i]); //index of the input character
		
		if (iter->next[j] != NULL ) { //if the next letter exits
			iter = iter->next[j]; //go to the next letter
		
		} else {
			return false; //if it doesn't exist, it's not a word yet.
		}
		
		//if you've iterated to the end of the word, and it's a designated end
		if ((i == (len - 1)) && iter->isEnd) { 
			return true; 
		}
	}
	return false;
}


//-----------------------------------------------------------------------------
//								INSERT FUNCTIONS
//-----------------------------------------------------------------------------

//insert puts strings into our dictionary.
//it cleans the string first, to remove non-alpha chars and make all lowercase.
//if it's empty, it inserts the empty string. 
//if it's already in there, it doesn't do anything but return true for insert.
//otherwise, it puts in the new nodes and everything required. 
bool Dictionary::insert(string s)
{
	s = clean(s);
	ins = false;

	if (isEmptyString(s)) {
		head->isEnd = true;
		ins = true;
	
	} else if (isWord(s)) {
		ins = true;
	} else {
		insertNew(s); //if word isn't already in dictionary
	}
	return ins;
}


//inserts a completely new string. it either marks the existing middle
//of a word as the end of one (creating a prefix) or it inserts leaves to
//"forge a new path" and create a completely new word. 
void Dictionary::insertNew(string s)
{
	unsigned int len = s.length();
	Node* iter = head;
	int j;

	for (unsigned int i = 0; i < len; i++) {
		
		j = charToInt(s[i]); //alphabetical index of char to insert

		if (iter->next[j] == NULL) {
			//creates a leaf and advances iter to the leaf
			iter->next[j] = insertLeaf(s[i]);
		}
		
		iter = iter->next[j]; //advance iterator

		//checks if you've inserted to the end of the word
		if (i == (len - 1)) { 
			iter->isEnd = true;
			ins = true;
			return;
		} else if (iter == NULL) {
			return; //failed to allocate memory
		}
	}
}



//creates a new leaf with value c. 
//if the leaf is null, it means mem allocation failed and it doesn't 
//do anything. there are later checks that will respond to this mem
//allocation failure. it returns the node always.
Node* Dictionary::insertLeaf(char c)
{
	Node* leaf = makeNode();
	if (leaf != NULL) {
		leaf->value = c;  
	}
	return leaf;
}


//a "constructor" for a node that makes a new
//node and initializes everything.
Node* Dictionary::makeNode()
{
	Node* toMake = new (nothrow) Node;
	toMake->value = '$';  //sentinel value for non-initialized node
	toMake->isEnd = false;
	
	for (int i = 0; i < ALPHA_SIZE; i++) {
		toMake->next[i] = NULL; //initializes all next letters to NULL
	}
	return toMake;
}

