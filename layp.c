#include <stdio.h>
#include <ctype.h>

#define FILENAME "test"
#define SYMB_UNKNOWN 0

typedef struct{
	char *date;
	int layer;
	int symbol;
} token;

void interpret(char *filename);
void pars(FILE *fptr);

int main() {
	interpret(FILENAME);
	return 0;
}

void interpret(char *filename) {
	FILE *fptr = fopen(filename, "r");
	pars(fptr);
	fclose(fptr);
}

void token_init(token *tok) {
	tok->date = NULL;
	tok->layer = 1;
	tok->symbol = SYMB_UNKNOWN;
}

void pars(FILE *fptr) {
	return;
}
