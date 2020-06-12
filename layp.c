#include <stdio.h>
#include <ctype.h>

#define FILENAME "test"
#define LEN 256

#define SYMB_UNKNOWN 0
#define SYMB_ELEMENT ' '
#define SYMB_LAYER ';'
#define SYMB_BRANCH ','
#define SYMB_TREE '/'
#define SYMB_UNION '\"'

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
	token tok;
	int c;


}
