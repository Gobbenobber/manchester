#pragma once

#include "stringToManchester.h"
#include <stdio.h>

/* Test af stringToManchester */

int main() {

	char* str = "Tekst som skal konverteres til manchester kode.";	

	printf("%s", stringToManchester(str));

	int x;
	scanf("%d", &x);
}