#pragma once

#include "Manchester.h"
#include <stdio.h>



int main() {

	/* Test af stringToManchester */

	unsigned char* str = "ABCD";	

	printf("\n\n\t\t\t Den indtastede tekststreng er: %s \n", str);

	printf("\n\n\t\t\t Oversat til Manchester laeses dette (som chars): %s \n", stringToManchester(str));
	free(stringToManchester(str));
	
	printf("\n\n\t\t\t Oversat tilbage til almindelig binaer kode laeses det igen (som chars) som: %s \n", mancesterToString(stringToManchester(str)));
	free(mancesterToString(stringToManchester(str)));

	while (1)
	{	
		int f;
		scanf("%d", &f);
	}
} 