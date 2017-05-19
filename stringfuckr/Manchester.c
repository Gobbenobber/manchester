#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Manchester.h"

static unsigned char * manchesterPtr = 0;

void freePtr(){
	free(manchesterPtr);
}

const unsigned char* stringToManchester(const unsigned char* toBeConverted)
{
	if (toBeConverted == NULL) return 0;									// Hvis der ikke er input, return 0 
	int len = strlen(toBeConverted);										// Lav size_t som kan passes til calloc.
	manchesterPtr = (unsigned char *)calloc(((len+1) * 2)+1, 1);				// Alloker hukommelse
	int counter = 8;
	int t = 0;

	for (int i = 0; i <= len; ++i)
	{
		unsigned char ch = toBeConverted[i];

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
				manchesterPtr[i + t] |= 1 << counter;
				--counter;
				manchesterPtr[i + t] &= (255 - (0 << counter));
			}
			else
			{
				manchesterPtr[i + t] &= (255 - (0 << counter));
				--counter;
				manchesterPtr[i + t] |= (1 << counter);
			}
		}
		--t;															// Find næste character i array af chars som skal konverteres.
	}
	return manchesterPtr;													// Returnér manchesterkoden
}

unsigned char* mancesterToString(const unsigned char* toBeConverted)
{
	if (toBeConverted == NULL) return 0;
	int len = (strlen(toBeConverted) / 2);
	unsigned char* toString = calloc((len+1), sizeof(unsigned char));
	if (toString == NULL)
	{
		return NULL;
	}
	int i = 0;
	int z = 7;
	int p = 7;

	for (int j = 0; j <= len * 2; j++)
	{
		unsigned char ch = toBeConverted[j];

		for (size_t timestocheck = 0; timestocheck <= 3; timestocheck++)
		{
			if (ch == '\0')
			{
				toString[i + 1] = '\0';
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
			if (ch & (1 << p) && (ch | (0 << (p - 1))))
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