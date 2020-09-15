#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>
//gcc main.c -ledit


typedef struct {
	char *expr;
	char *type;
} atom_t;

typedef struct {
	char *var;
	char *type;
} ctx_atom_t;

int judge_context(ctx_atom_t *gamma) {
	if(gamma->var==NULL) {
		return 1; }
	if(!judge_same_type(gamma->type, gamma->type)) {
		return 0; }
	int i;
	for(i=0; (gamma+i)->var!=NULL; i++) {	//not really efficient, O(n!)
		if(str_eq(gamma->var, (gamma+i)->var)) { return 0; }}
	return judge_context(gamma+1); }

//sort all judgements by type of hypotheses for efficient lookup

//(axiom (: zero Nat))
//(axiom (: n Nat) (: (succ n) Nat))
//(axiom (n Nat) (: (U n) (U (succ n))))
//(axiom ==

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
