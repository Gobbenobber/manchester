#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

char* stringToManchester(char* s) {
	if (s == NULL) return 0;							/* Hvis der ikke er input, return 0 */
	size_t len = strlen(s);
	char* manchester = (char *) malloc(len * 16 + 1);	// Hver char er en byte (8 bits) * 2 for manchester og + 1 til sidst for null terminator
	manchester[0] = '\0';
	for (size_t i = 0; i < len; ++i) {
		char ch = s[i];
		for (int j = 7; j >= 0; --j) {
			if (ch & (1 << j)) {
				strcat(manchester, "10");
			}
			else {
				strcat(manchester, "01");
			}
		}
	}
	return manchester;
}


//void stringToMancester(char* inString)
//{
//	int bitArray[sizeof(inString)][7];
//	char *temp;
//	char bitArrayTotal[sizeof(inString)][15];
//
//	for (temp = inString; *temp; ++temp)
//	{
//		int bit_index;
//		for (bit_index = 14; bit_index >= 0; bit_index -= 2)
//		{
//			int bit = *temp >> bit_index & 1;
//			bitArray[bit_index][*temp] = bit;			//Remember to cycle through with [7:0][0:String]
//
//			if (bitArray[bit_index][*temp] == 0)
//			{
//				bitArrayTotal[bit_index][*temp] = '0';
//				bitArrayTotal[bit_index + 1][*temp] = '1';
//			}
//			else if (bitArray[bit_index][*temp] == 1)
//			{
//				bitArrayTotal[bit_index][*temp] = '1';
//				bitArrayTotal[bit_index + 1][*temp] = '0';
//			}
//		}
//	}
//	
//	for (char* i = inString; *i; ++i)
//	{
//		for (int j = 14; j >= 0; j -= 2)
//		{
//			cout << bitArrayTotal[j][*i];
//		}
//		cout << endl;
//	}
//}