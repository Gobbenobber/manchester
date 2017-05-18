#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


unsigned char* stringToManchester(unsigned char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;									// Hvis der ikke er input, return 0 
	size_t len = strlen(toBeConverted);										// Lav size_t som kan passes til calloc.
	unsigned char* manchester = calloc(len*2,8);							// Alloker hukommelse
	manchester[0] = '\0';
	int counter = 8;
	int t = 0;

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
		--t;											// Find næste character i array af chars som skal konverteres.
	}
	return manchester;									// Returnér manchesterkoden
}

unsigned char* mancesterToString(unsigned char* toBeConverted) 
{
	if (toBeConverted == NULL) return 0;
	size_t len = (strlen(toBeConverted)/2);
	unsigned char* toString = calloc(len, 8);
	toString[0] = '\0';
	int i = 0;
	int z = 7;
	int p = 7;
	
		for (int j = 0; j <= len * 2; j++)
		{
			unsigned char ch = toBeConverted[j];

			for (size_t timestocheck = 0;  timestocheck <= 3;  timestocheck++)
			{
				if (ch == NULL)
				{
					toString[i+1] = '\0';
					break;
				}

				if (p < 0)
				{
					p = 7;
				}

				if (z < 0)
				{
					z = 7;
					i++;
					toString[i] = '\0';
				}

				if (ch & (1 << p) && (ch | (0 << p - 1)))
				{
					toString[i] |= (1 << z);
					z--;
					p -= 2;
				}

				else /*if (ch & (0 << z) && (ch | (1 << z - 1)))*/
				{
					toString[i] &= (255 - (0 << z));
					z--;
					p -= 2;
				}
			}
		}	
	return toString;
}