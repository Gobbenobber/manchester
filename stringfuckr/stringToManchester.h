#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* stringToManchester(char* toBeConverted) {
	if (toBeConverted == NULL) return 0;						// Hvis der ikke er input, return 0 
	size_t len = strlen(toBeConverted);							// Lav size_t som kan passes til malloc.
	char* manchester = (char *) malloc(len * 2);				// Hver char er en byte (8 bits) * 2 for manchester (>og + 1 til sidst for null terminator?<)
	manchester[0] = '\0';
	for (size_t i = 0; i < len; ++i) {
		char ch = toBeConverted[i];								// Find næste character i array af chars som skal konverteres.
		for (int j = 7; j >= 0; --j) {
			if (ch & (1 << j)) {								// AND hver bit med 1, startende fra LSB. Vi benytter G. E. Thomas manchester kode. 1 = "10" og 0 = "01".
				strcat(manchester, "10");
			}
			else {
				strcat(manchester, "01");
			}
		}
	}
	return manchester;											// Returnér manchesterkoden
}