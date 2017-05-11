#pragma once
//#include <string>
//#include <bitset>
//#include <iostream>
//#include <vector>
//#include <iterator>
#include "stringToManchester.h"
#include <stdio.h>

int main() {


	/*
	
	string originalString_ = "0HH216";
	bitset<8> *array_ = new bitset<8>[originalString_.length()];
	vector<string> modifiedString_;

	for (size_t i = 0; i < originalString_.length(); i++)
	{
		array_[i] = bitset<8>(originalString_[i]);
	}

	for (size_t j = 0; j < originalString_.length(); j++)
	{
		for (size_t i = 0; i < 8; i++)
		{
			if (array_[j][i] == false)
			{
				modifiedString_.push_back("01");
			}
			else if (array_[j][i] == true)
			{
				modifiedString_.push_back("10");
			}
		}
	}

	for (vector<string>::const_iterator i = modifiedString_.begin(); i != modifiedString_.end(); ++i)
	{
		cout << *i;
	}
	cout << endl;
	
	*/


	char* str = "Susanne";

	printf("%s", stringToManchester(str));

	int x;
	scanf("%d", &x);
}