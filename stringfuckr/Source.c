#pragma once
//#include <string>
//#include <bitset>
//#include <iostream>
//#include <vector>
//#include <iterator>
#include "stringToManchester.h"
#include <stdio.h>

/* Test af stringToManchester */

int main() {

	char* str = "Tekst som skal konverteres til manchester kode.";	

	printf("%s", stringToManchester(str));

	int x;
	scanf("%d", &x);
}