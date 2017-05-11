#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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