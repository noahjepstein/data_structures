//-----------------------------------------------------------------------------
// Filename: scorerMain.cpp
// Author:   Noah J. Epstein
// Date:     12/3/2013
// Rev-Date: 12/11/2013
//
// Description: Scorer program for lists of boggle words of variable size.
//				Calculates the score by calculating word length and then 
//				adding the score of an input word to the tally if it's a valid
//				word.
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


int main()
{
	int i = 0;
	string input;
	int k = 0; 
	int score = 0;
	int wordLen;

	while (!cin.eof()) {
		
		cin >> input;

		if ((i % 3) == 0) { //1 or 0 part of input
			k = atoi(input.c_str());
		} else if (((i - 2) % 3) == 0) { //word part of input
			
			//to make it faster
			//has different buckets for each boggle point value
			wordLen = input.length();
			if (wordLen > 7) {
				score += (k * 11);
			} else if (wordLen == 7) {
				score += (k * 5);
			} else if (wordLen == 6) {
				score += (k * 3);
			} else if (wordLen == 5) {
				score += (k * 2);
			}else if (wordLen < 5) {
				score += k;
			}
		}
		i++; 
	}
	// i/3 gives the number of words, score has tallied the points
	cout << (i / 3) << " words " << score << " points";
	return 0; 
}
