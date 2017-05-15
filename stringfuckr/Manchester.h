#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char* stringToManchester(char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;						// Hvis der ikke er input, return 0 
	size_t len = strlen(toBeConverted);							// Lav size_t som kan passes til malloc.
	char* manchester = (char *) malloc(len * 2);				// Hver char er en byte (8 bits) * 2 for manchester (>og + 1 til sidst for null terminator?<)
	manchester[0] = '\0';
	for (size_t i = 0; i < len; ++i) {
		char ch = toBeConverted[i];								// Find n�ste character i array af chars som skal konverteres.
		for (int j = 7; j >= 0; --j) {
			if (ch & (1 << j)) {								// AND hver bit med 1, startende fra LSB. Vi benytter G. E. Thomas manchester kode. 1 = "10" og 0 = "01".
				strcat(manchester, "10");
			}
			else {
				strcat(manchester, "01");
			}
		}
	}
	return manchester;											// Return�r manchesterkoden
}

char* mancesterToString(char* toBeConverted) {
	if (toBeConverted == NULL) return 0;
	int len = (strlen(toBeConverted) / 16) - 1;
	char* tempString = (char *) malloc(len * 8);
	char* toString = (char *)malloc(len);
	toString[0] = '\0';
	tempString[0] = '\0';

	for (int i = 0; i <= len; i++)
	{
		for (int j = 0; j < 16; j += 2)
		{
			if ((toBeConverted[(i * 16) + j] == '0') && (toBeConverted[((i * 16) + j) + 1] == '1'))
			{
				strcat(tempString, "0");
			}
			else
			{
				strcat(tempString, "1");
			}
		}
	}
	return tempString;
}