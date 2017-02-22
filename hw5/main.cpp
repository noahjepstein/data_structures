//main.cpp
//for testing on dictionary

#include "dictionary.h"

int main()
{
	Dictionary dic;

	string s1 = "";
	string s2 = "a";
	string s3 = "apple";
	string s4 = "lsdkj@#$#@RGFSRT$#@RFSE#W#fjaslfjvnrjntrjrtj";
	string s5 = s1 + s2 + s3 + s4;
	string s6 = "2234@%%@@#$@#@@@";

	cout << "empty with empty: should be 11" << endl;
	dic.insert(s1 + s1);
	cout << dic.isWord(s1) << dic.isPrefix(s1) << endl;

	cout << "empty with complex char: should be 11" << endl;
	dic.insert(s1);
	dic.insert(s1 + s6);
	dic.insert(s6);
	cout << dic.isWord(s1) << dic.isWord(s6) << endl;

	cout << "something concat with empty" << endl;
	dic.insert("apple" + s1);
	cout << dic.isWord("apple") << dic.isPrefix("a") << endl;

	cout << "weird words" << endl;
	dic.insert(s1);
	dic.insert(s2);
	dic.insert(s3); 
	dic.insert(s4);
	dic.insert(s5);
	dic.insert(s6);
	dic.insert(s4 + s3);
	cout << dic.isPrefix(s4) << endl;
	cout << dic.isWord(s4) << endl;
	cout << dic.isWord("b") << endl;
	for (int i = 0; i < 15; i++){
		s3 += s3;
	}
	dic.insert(s3);


	return 0;
}
