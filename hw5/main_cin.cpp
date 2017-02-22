//main_cin.cpp

#include "dictionary.h"


int main()
{
	Dictionary dic;

	while (true) {
		string s;
		cin >> s;
		dic.insert(s);
		cout << dic.isWord(s) << endl;
		cout << dic.isPrefix(s) << endl;
		if (cin.eof()){
			break;
		}
	}
}