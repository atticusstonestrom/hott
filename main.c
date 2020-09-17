#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>
//gcc main.c -ledit

//scrub all whitespace including double spaces
//int scrub();


/*typedef struct {
	char *expr;
	char *type;
} atom_t;

typedef type_t char *;
typedef var_t  char *;

typedef struct ctx_atom_t {
	//struct ctx_atom_t *next;
	var_t var;
	type_t type;
} ctx_atom_t;*/

//should context be a hash map? much more efficient
//memoization
//first check built-in types, then check axioms

//to check if ascii, use mask:	?
//	0x000000

/*int judge_same_type() {
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
	return judge_lookup(gamma+1, to_lookup, to_fill); }*/

//sort all judgements by type of hypotheses for efficient lookup

//(axiom (: zero Nat))
//(axiom (: n Nat) (: (succ n) Nat))
//(axiom (n Nat) (: (U n) (U (succ n))))
//(axiom ==

char *input;
//struct *tree;
//struct with id for expression or atom

//catch ctrl c interrupt

//colors!!

//buffer output
int print_tree(char *input, int depth) {
	if(input[0]!='(') {
		printf("missing paranthesis\n");
		return 0; }
	if(input[1]==' ') {
		printf("unexpected space after '('\n");
		return 0; }
	int i, j;
	//int depth=0;
	char *last=input+1;
	for(i=1; input[i]!=0; i++) {
		switch(input[i]) {
		case '(':
			//printf("in\n");
			if(input[i-1]!=' ' && input[i-1]!='(') {
				printf("expected space before expression\n");
				return 0; }
			printf("\n");
			j=print_tree(input+i, depth+1);
			if(!j) { return 0; }
			i+=j;
			if(input[i]!=' ' && input[i]!=')') {
				printf("expected space between expressions\n");
				return 0; }
			if(input[i+1]!='(') {
				printf("\n"); }
			if(input[i]==')') {
				i--; }
			last=input+i+1;
			break;
		case ')':
			if(depth==0 && input[i+1]!=0) {
				printf("unexpected ')'\n");
				return 0; }
			if(input[i-1]==' ') {
				printf("unexpected space before ')'\n");
				return 0; }
			for(j=0; j<depth; j++) { putchar('\t'); }
			printf("%.*s\n", (int)((input+(long)i)-last), last);
			return i+1;
			break;
		case ' ':
			for(j=0; j<depth; j++) { putchar('\t'); }
			printf("%.*s\n", (int)((input+(long)i)-last), last);
			last=input+i+1;
			break;
		default:
			continue;
			break; }; }
	return 0; }

int main(int argc, char **argv) {
	puts("press ctrl+d to exit\n");
	int ret;
	while(1) {
		input=readline("idris> ");
		add_history(input);
		//printf("%s\n", input);
		printf("\n");
		ret=print_tree(input, 0);
		printf("\nparsed input [%s]\n", ret ? "success":"fail");
		free(input); }
	return 0; }
