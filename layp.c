#include <stdio.h>
#include <ctype.h>
#include "tree.h"

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
	tree st; // syntax tree
	tree *st1 = NULL, *st2 = NULL;
	tree_init(&st);

	tree_set_data(&st, "hello tree!");
	printf("tree  data: %s\n", st.data);

	tree_set_n(&st, 2);
	st1 = (tree *)(st.list[0]);
	st2 = (tree *)(st.list[1]);
	tree_init(st1);
	tree_init(st2);
	tree_set_data(st1, "3.14");
	tree_set_data(st2, "625");
	
	printf("tree1 data: %s\n", st1->data);
	printf("tree2 data: %s\n", st2->data);

	tree_free(st1);
	tree_free(st2);
	tree_free(&st);
	printf("tree data: %s\n", st.data);
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
