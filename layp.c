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
	char buf[LEN];
	int c = 0, i = 0, is_symbol = 1, layer = 0, branch = 0, elem = 0;

	c = fgetc(fptr);
	while (!feof(fptr)) {
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
				is_symbol = 0;
				buf[i++] = c;
				break;
		}
		if (!is_symbol++) {
			buf[i] = '\0';
			i = 0;
			treeBuild(buf, layer, branch, elem);
		}
		c = fgetc(fptr);
	}
}

void treeBuild(char *data, int layer, int branch, int elem) {
	printf("sheet: %s, layer=%d, branch=%d, elem=%d\n",
					data, layer, branch, elem);
}
