#pragma once

#include "Manchester.h"
#include <stdio.h>

/* Test af stringToManchester og manchesterToString */

int main() {

	unsigned char* str = "NU VIRKER DET HER ENDELIG";	
	unsigned char* str2 = "0110100101011010011010011010101001101001011001010110100101100110";

	printf("%s \n", stringToManchester(str));

	printf("%s \n", mancesterToString(str2));
	printf("%s \n", mancesterToString(stringToManchester(str)));


	while (1)
	{	
		int f;
		scanf("%d", &f);
	}
} 