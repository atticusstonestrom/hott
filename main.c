#include <stdio.h>

char input[2048];

//catch ctrl c interrupt

int main(int argc, char **argv) {
	puts("press ctrl+d to exit");
	while(1) {
		fputs("idris> ", stdout);
		fgets(input, 2048, stdin);
		printf("\t%s\n", input); }
	return 0; }
