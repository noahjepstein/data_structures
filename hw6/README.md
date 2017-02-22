DATA STRUCTURES - BOGGLE SOLVER, VALIDATOR, AND SCORER
AUTHOR: NOAH J EPSTEIN
-------------------------------------------------------------------------------

BogWordList.h

BogSolver.h
BogSolver.cpp
solverMain.cpp

BogValidator.h
BogValidator.cpp
checkerMain.cpp

scorerMain.cpp

dictionary.h
dictionary.cpp

-----------------

Compilation instructions:

g++ -Wall -Wextra BogSolver.cpp solverMain.cpp dictionary.cpp -o bbsolver
g++ -Wall -Wextra BogValidator.cpp BogSolver.cpp dictionary.cpp checkerMain.cpp -o bbchecker
g++ -Wall -Wextra scorerMain.cpp -o bbscorer

-----------------

This program features three major components: a boggle board solver, a
validator for guesses that may be solutions, and a scorer that takes
in a series of words in a specific format and scores them per the rules
of Boggle.

The solver has a few major parts. It has a constructor and destructor, as
would be typical for a class, using a recursive implementation for the
destructor. It has a collection of functions for reading in data from input:
it reads in a dictionary, the words of which are stored in a trie. It then
reads in a list of letters for a boggle board. The letters themselves are
stored as a dynamic array called an adjacency list: each letter has a
linked list coming from it that lists letters to which it's adjacent. Once
the dictionary and adjacency list are in place, all data has been processed
from cin on the solver's behalf. Next, the program has functions for finding
solutions to the board. A function walks around the adjacency list, recursing
on adjacent letters if they form prefixes of words. When a word is created
by the stack of function calls, it's added to the list of found words and
addionally added to a two-dimensional list of letters called a BogWordList.
Then there are a handful of functions for returing data about the words that
were found. Some return the number of words, words of a specific length,
some return the whole BogWordList, and some print the list to the screen.

The BogValidator class leans heavliy on the solver to do its heavy lifting.
It gets a bogwordlist from the sovler itself, but from there, all it's doing
is comparing words from cin to words that were found by the solver. If the
word from input matches one found by the solver (stored in a trie using the
dictionary class for fast lookup and insertion) then the word is validated
and the validator prints a message indicating so.

The scorer is a simple program that takes in a list of words in a specified
format that indicates whether or not each word is valid. It uses no data
structures other than those featured in standard namespace.

-------------------------------------------------------------------------------
				   Boggle Board Indexing Format Diagram
-------------------------------------------------------------------------------

				B0    R1    L2    L3

				E4    G5    A6    D7

				O8	  A9    V10   I11

				V12   O13   C14   N15

If each location on the board features a letter and a number, and the
width and height of the board are known, all that is necessary to fully specify
the boggle board is the letter and the index of the tile. From this, we can
determine row and column location, as well as all locations of adjacency.
