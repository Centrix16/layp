#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void tree_init(tree *tr) {
	tr->data = NULL;
	tr->n = 0;
	tr->list = NULL;
}

void tree_add(tree *tr) {
	tree *list;
	
}

void tree_set_n(tree *tr, int n) {
	tr->n = n;
	tr->list = malloc(n * sizeof(tree *));
	for (int i = 0; i < n; i++)
		tr->list[i] = malloc(sizeof(tree));
}

void tree_set_data(tree *tr, char *data) {
	int size = strlen(data);
	tr->data = malloc((size + 1) * sizeof(char));
	strcpy(tr->data, data);
}

void tree_free(tree *tr) {
	tr->n = 0;
	tr->data = NULL;
}
