#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>
//gcc main.c -ledit

char *input;

//catch ctrl c interrupt

int main(int argc, char **argv) {
	puts("press ctrl+d to exit\n");
	while(1) {
		input=readline("idris> ");
		add_history(input);
		printf("%s\n", input);
		free(input); }
	return 0; }
