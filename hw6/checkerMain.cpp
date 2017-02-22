//-----------------------------------------------------------------------------
// Filename: BogSolver.cpp
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Implementation of Boggle board solver.
//-----------------------------------------------------------------------------

#include "BogValidator.h"

int main()
{
	BogValidator v;

	v.readDict();
	v.readBoard();
	v.checkWords();
	return 0;
} 
