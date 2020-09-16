#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>
//gcc main.c -ledit


typedef struct {
	char *expr;
	char *type;
} atom_t;

typedef type_t char *;
typedef var_t  char *;

typedef struct ctx_atom_t {
	//struct ctx_atom_t *next;
	var_t var;
	type_t type;
} ctx_atom_t;

//should context be a hash map? much more efficient
//memoization
//first check built-in types, then check axioms

//to check if ascii, use mask:	?
//	0x000000

int judge_same_type() {
	hypothesissame;
	typesame;
	return 0; }

int judge_context(ctx_atom_t *gamma) {
	if(gamma->var==NULL) {
		return 1; }
	if(!judge_same_type(gamma->type, gamma->type)) {
		return 0; }
	//int i;
	//for(i=0; (gamma+i)->var!=NULL; i++) {	//not really efficient, O(n!)
	//	if(str_eq(gamma->var, (gamma+i)->var)) { return 0; }}
	//return judge_context(gamma->next);
	return judge_context(gamma+1); }

int judge_lookup(ctx_atom_t *gamma, var_t *to_lookup, type_t *to_fill) {
	if(gamma->var==NULL) {
		return 0; }
	if(str_eq(gamma->var, to_lookup)) {
		strncpy(to_fill, gamma->type);
		return 1; }
	return judge_lookup(gamma+1, to_lookup, to_fill); }

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
