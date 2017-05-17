#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char* stringToManchester(char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;								// Hvis der ikke er input, return 0 
	size_t len = strlen(toBeConverted);									// Lav size_t som kan passes til malloc.
	unsigned char* manchester = (unsigned char *) malloc((len * 2) + 1);		// Hver char er en byte (8 bits) * 2 for manchester (>og + 1 til sidst for null terminator?<)
	manchester[0] = '\0';
	for (size_t i = 0; i < len; ++i) {
		unsigned char ch = toBeConverted[i];							// Find næste character i array af chars som skal konverteres.
		for (int j = 7; j >= 0; --j) {
			if (ch & (1 << j)) {										// AND hver bit med 1, startende fra LSB. Vi benytter G. E. Thomas manchester kode. 1 = "10" og 0 = "01".
				strcat(manchester, "10");
			}
			else {
				strcat(manchester, "01");
			}
		}
	}
	return manchester;													// Returnér manchesterkoden
}

unsigned char* mancesterToString(unsigned char* toBeConverted) {
	if (toBeConverted == NULL) return 0;
	int len = (strlen(toBeConverted) / 16) - 1;
	unsigned char* tempString = (unsigned char *)malloc(len * 8);
	unsigned char* toString = (unsigned char *)malloc(len);
	tempString[0] = '\0';
	toString[0] = '\0';

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
	
	int i = 0;
	int z = 7;

		for (int j = 0; j <= ((len + 1) * 8); j++)
		{
			if (z < 0)
			{	
				z = 7;
				i++;
				toString[i] = '\0';
			}

			if (tempString[j] == '1')
			{
				toString[i] |= (1 << z);
				z--;
			}
			else if (tempString[j] == '0')
			{
				toString[i] &= (255 - (0 << z));
				z--;
			}
			else if (tempString[j] == NULL)
			{
				toString[i+1] = '\0';
			}
		}	
	return toString;
}