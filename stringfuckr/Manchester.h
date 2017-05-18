#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


unsigned char* stringToManchester(unsigned char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;									// Hvis der ikke er input, return 0 
	int len = sizeof(toBeConverted);										// Lav size_t som kan passes til malloc.
	unsigned char* manchester = calloc(len*2,8);						// Alloker hukommelse
	manchester[0] = '\0';
	size_t counter = 8;
	size_t t = 0;
	for (int i = 0; i <= len; ++i) 
	{
		unsigned char ch = toBeConverted[i];
		if (ch == NULL)
		{
			manchester[i+t+1] = '\0';
			break;
		}
		for (int j = 7; j >= 0; j--)
		{
			--counter;
			if (counter < 0 || counter > 7)
			{
				counter = 7;
				++t;
			}
			if (ch & (1 << j))
			{	
				manchester[i + t] |= 1 << counter;
				--counter;
				manchester[i + t] &= (255 - (0 << counter));
														// AND hver bit med 1, startende fra LSB. Vi benytter G. E. Thomas manchester kode. 1 = "10" og 0 = "01".
			}
			else
			{
				manchester[i + t] &= (255 - (0 << counter));
				--counter;
				manchester[i + t] |= (1 << counter);
				
			}
		}	
		--t;											// Find n�ste character i array af chars som skal konverteres.
	}
	return manchester;													// Return�r manchesterkoden
}

unsigned char* mancesterToString(unsigned char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;
	int len = ((strlen(toBeConverted)/2)/8);
	unsigned char* tempString = calloc(len, 8);
	unsigned char* toString = calloc(len, 8);
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