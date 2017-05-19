#pragma once

#include "Manchester.h"
#include <stdio.h>

	/* Test af Manchester.h */

int main() {

	/* Streng som skal sendes via X10 som manchester kode */
	const unsigned char* str = "ABCD";	

	printf("\n\n\t\t\t Den indtastede tekststreng er: %s \n", str);

	/* Test af stringToManchester() */

	printf("\n\n\t\t\t Oversat til Manchester laeses dette (som chars): %s \n", stringToManchester(str));


	/* Test af manchesterToString() */

	printf("\n\n\t\t\t Oversat tilbage til almindelig binaer kode laeses det igen (som chars) som: %s \n", mancesterToString(stringToManchester(str)));
	freePtr();

	/* U gon' get stuck in here - do CTRL+C to exit */

	int f = 1;

	while (f != 0)
	{	
		scanf_s("%d", &f);
	}
} 