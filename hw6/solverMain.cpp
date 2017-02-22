// solverMain.cpp -- required program file; description in Boggle Overview

#include "BogSolver.h"

int main()
{
	BogSolver solver;

	solver.readDict();
	solver.readBoard();
	solver.solve();
	solver.printWords();
	return 0;
}

