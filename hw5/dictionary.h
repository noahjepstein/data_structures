//-----------------------------------------------------------------------------
// Filename: dictionary.h
// Author:   Noah J. Epstein
// Date:     11/22/2013
// Rev-Date: 11/22/2013
//
// Description: Header for dictionary data structure, implemented with a trie.
// 				Cannot accept any strings as words longer than 2^17 characters. 
//				Otherwise, the stack overflows becuase recursive function calls 
//				fill it. 
//-----------------------------------------------------------------------------

#include <cctype>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

const int ALPHA_SIZE = 26; 

struct Node
{
	char value; //has a letter stored in here

	bool isEnd; //is this character the end of a word?

	//array of next nodes that represent the next letters in a word
	Node* next[ALPHA_SIZE]; 
};

class Dictionary
{
public: 

	//constructs an empty dictionary with "" as only element. 
	Dictionary(); 

	//destructor for dictionary class.
	~Dictionary();

	//determines if a word is a prefix. 
	bool isPrefix(string s);

	//determines whether a string is a word in our dictionary.
	bool isWord(string s);

	//inserts a new word into our dictionary. returns true if successful,
	//false if it failed to insert (only possible due to malloc). 
	bool insert(string s);

//private:

	//helper function for the destructor that recursively deletes everything
	void delete_recursive(Node* root);

	bool isEmptyString(string s);

	//checks if a given node is a leaf - leaf meaning that 
	//no words continue on past this node. you cannot call 
	//isLeaf on a null pointer.
	bool isLeaf(Node* node);

	//checks if a word with length > 0 is in the dictionary
	bool checkNonEmptyWord(string s);

	//checks if a non-empty word is a prefix
	bool checkPrefix(string s);

	//the empty string that sits atop our dictionary.
	//one node to rule them all
	Node* head;

	//intermediate bool for insert to use while inserting.
	bool ins; 

	//constructor for Node struct that sets all pointers in node to NULL
	Node* makeNode();

	//removes all non-alpha characters and changes all uppercase
	//alpha characters to lowercase.
	string clean(string s);

	//inserts a new word into the dictionary. 
	void insertNew(string s);

	//inserts a new leaf node. for example, if we want to add
	//"cat" to the dictionary, and "car" is already in the dictionary,
	//insertLeaf is used to add a 't' leaf to the 'a' that both words 
	//share.
	Node* insertLeaf(char c);

	//returns the index of a character in reference to its
	//position in the alphabet.
	int charToInt(char c);

};

