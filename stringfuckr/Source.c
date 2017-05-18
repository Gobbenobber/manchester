#pragma once

#include "Manchester.h"
#include <stdio.h>

/* Test af stringToManchester og manchesterToString */

int main() {

	unsigned char* str = "ABCD";	
	printf("%s \n", stringToManchester(str));



	//printf("%s \n", stringToManchester(str));
	
	printf("%s \n", mancesterToString(stringToManchester(str)));
	

	while (1)
	{	
		int f;
		scanf("%d", &f);
	}
} 