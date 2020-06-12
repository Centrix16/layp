#include <stdio.h>
#include <ctype.h>

#define FILENAME "test"
#define LEN 256

#define SYMB_UNKNOWN 0
#define SYMB_ELEMENT 1
#define SYMB_LAYER 2
#define SYMB_BRANCH 3
#define SYMB_TREE 4
#define SYMB_UNION 5

typedef struct{
	char *data;
	int layer;
	int symbol;
} token;

void interpret(char *filename);
void pars_file(FILE *fptr);

int main() {
	interpret(FILENAME);
	return 0;
}

void interpret(char *filename) {
	FILE *fptr = fopen(filename, "r");
	pars_file(fptr);
	fclose(fptr);
}

void token_init(token *tok) {
	tok->data = NULL;
	tok->layer = 1;
	tok->symbol = SYMB_UNKNOWN;
}

void pars_file(FILE *fptr) {
	
	return;
}
