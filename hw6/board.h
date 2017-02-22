//-----------------------------------------------------------------------------
// Filename: board.h
// Author:   Noah J. Epstein
// Date:     12/6/2013
// Rev-Date: 12/6/2013
//
// Description: Header file for boggle board data structure.
//-----------------------------------------------------------------------------


#include "BogWordList.h"


class Board
{
public:

	Board();

	~Board();

private:

	void readBoard(); //reads in a board from cin. used for construction

	bool isEdge(int index);

	

	int height;

	int width;

	int nLetters;

};