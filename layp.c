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
	int c = 0, i = 0, layer = 0, branch = 0, elem = 0;

	c = fgetc(fptr);
	while (!feof(fptr)) {
		switch (c) {
			case SYMB_ELEMENT:
				buf[i++] = '\0';
				printf("string: %s! c=\'%c\' l=%d b=%d e=%d\n", buf, c, layer, branch, elem);
				elem++;
				i = 0;
				break;
			case SYMB_LAYER:
				buf[i++] = '\0';
				printf("string: %s! c=\'%c\' l=%d b=%d e=%d\n", buf, c, layer, branch, elem);
				layer++; branch = 0; elem = 0;
				i = 0;
				break;
			case SYMB_BRANCH:
				buf[i++] = '\0';
				printf("string: %s! c=\'%c\' l=%d b=%d e=%d\n", buf, c, layer, branch, elem);
				branch++; elem = 0;
				i = 0;
				break;
			case SYMB_TREE:
				buf[i++] = '\0';
				printf("string: %s! c=\'%c\' l=%d b=%d e=%d\n", buf, c, layer, branch, elem);
				i = 0;
				break;
/*			case SYMB_UNION:
				buf[i++] = '\0';
				i = 0;
				break; */
			default:
				buf[i++] = c;
				break;
		}
		c = fgetc(fptr);
	}
}
