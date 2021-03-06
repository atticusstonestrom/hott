#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
//#include <editline/history.h>
//gcc main.c -ledit

//scrub all whitespace including double spaces
//(first replace tabs+newlines – mod depth – with spaces, then remove double spaces)
//then replace all lambda variables with deruijn indices
	//need some thought about nested lambdas (recursive call with depths?)
//int scrub();

typedef struct ctx_elem_t {
	int var;
	char *type;
} ctx_elem_t;
int judge_context(ctx_elem_t *gamma, int len);
int judge_type(ctx_elem_t *gamma, int len, 
	       char *expr, char *type);
int judge_same(ctx_elem_t *gamma, int len,
	       char *expr1, char *expr2, char *type);


int judge_context(ctx_elem_t *gamma, int len) {
	if(!len) { return 1; }
	if(gamma[len-1].var!=len-1) { return 0; }
	//if(!judge_context(gamma, len-1)) { return 0; }	//here?
		//"meta theoretic", so should check context in judge_type?
	return judge_type(gamma, len-1, gamma[len-1].type, "(U _)"); }

//vble

int judge_type(ctx_elem_t *gamma, int len, 
	       char *expr, char *type) {
	if(!judge_context(gamma, len)) { return 0; }
	//vble (should be char *, not int. say xi
	//U_i:U_{j}
	return 0; }

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

char *judge_fresh(ctx_atom_t *gamma) {}

char *judge_lookup(ctx_atom_t *gamma, char *to_lookup) {
	if(gamma->var==NULL) {
		return NULL; }
	if(str_eq(gamma->var, to_lookup)) {
		strncpy(to_fill, gamma->type);
		return 1; }
	return judge_lookup(gamma+1, to_lookup, to_fill); }

char *judge_type(ctx_atom_t *gamma, char *expr) {}

int judge_same_type(ctx_atom_t *gamma, char *expr1, char *expr2) {
	hypothesissame;
	typesame;
	return 0; }

char *judge_expr_core(ctx_atom_t *gamma, char *expr) {}

char *judge_type_core(ctx_atom_t *gamma, char *expr) {}

int judge_same_expr(ctx_atom_t *gamma, char *expr1, char *expr2, char *type) {}

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
