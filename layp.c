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

void interpret(char *filename);
void pars_file(FILE *fptr);
void treeBuild(char *data, int layer, int branch, int elem);
int is_symbol(char c);

int main() {
	interpret(FILENAME);
	return 0;
}

void interpret(char *filename) {
	FILE *fptr = fopen(filename, "r");
	pars_file(fptr);
	fclose(fptr);
}

void pars_file(FILE *fptr) {
	char buf[LEN] = {'\0'};
	int c = 0, i = 0, symbol_n = 1, layer = 0, branch = 0, elem = 0;

	c = fgetc(fptr);
	while (!feof(fptr)) {
		if (is_symbol(c) && i) {
			treeBuild(buf, layer, branch, elem);
		}
		switch (c) {
			case SYMB_ELEMENT:
				elem++;
				break;
			case SYMB_LAYER:
				layer++; branch = 0; elem = 0;
				break;
			case SYMB_BRANCH:
				branch++; elem = 0;
				break;
			case SYMB_TREE:
				break;
/*			case SYMB_UNION:
				break; */
			default:
				symbol_n = 0;
				buf[i++] = c;
				break;
		}
		if (symbol_n++)
			while(i)
				buf[--i] = '\0';

		c = fgetc(fptr);
	}
}

int is_symbol(char c) {
	switch(c) {
		case SYMB_ELEMENT:
		case SYMB_LAYER:
		case SYMB_BRANCH:
		case SYMB_TREE:
			return 1;
		default:
			return 0;
	}
}

void treeBuild(char *data, int layer, int branch, int elem) {
	printf("sheet: %s, layer=%d, branch=%d, elem=%d\n",
					data, layer, branch, elem);
}
