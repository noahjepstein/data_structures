//main.cpp
//for testing on dictionary

#include "dictionary.h"

int main()
{
	Dictionary dic;

	string s1 = "";
	string s2 = "a";
	string s5 = "apple";
	string s3 = "lsdkj@#$#@RGFSRT$#@RFSE#W#fjaslfjvnrjntrjrtj";
	string s4 = s5 + s1 + s2 + s3 + s5;
	dic.insert(s2);
	dic.insert(s5);
	dic.insert(s4);

	cout << dic.isWord(s1) << dic.isWord(s2) << dic.isWord(s3) 
	<< dic.isWord(s4) << dic.isWord(s5) << endl;



	return 0;
}
