//main_long.cpp
//tests long strings

#include "dictionary.h" 

int main()
{
	Dictionary dic;

	string s = "a";
	for (int i = 0; i < 17; i++) {
		cout << i << endl;
		s += s;
		dic.insert(s);
	}
	return 0;
}