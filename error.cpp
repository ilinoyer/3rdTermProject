#include<stdio.h>
#include<iostream>
#include "DataBaseTxt.h"


#define MAX_ERR 5
static char *p[] = { "",
" zle dane",
" otwarcie pliku",
" brak pamieci",
" Usage : ",
" nieznany ",
};

void error(int nr, char *str) 
{
	int k,choice;
	k = nr >= MAX_ERR ? MAX_ERR : nr;
	fprintf(stderr, "Blad(%d) -  %s %s\n", nr, p[k], str);
	system("pause");
	exit(nr);
}
