#pragma once

#include "stringToManchester.h"
#include <stdio.h>

/* Test af stringToManchester */

int main() {

	char* str = "a";	
	char* str2 = "0110100101011010011010011010101001101001011001010110100101100110";

	printf("%s", stringToManchester(str));
	printf("\n");
	printf("%s", mancesterToString(str2));


	while (1)
	{
		
	}
} 