#ifndef __TREE_H_INCLUDED__
#define __TREE_H_INCLUDED__

#define TREE_DATA_LEN

typedef struct {
	char *data;
	int n;
	struct tree **list;
} tree;

void tree_init(tree *tr);
void tree_set_data(tree *tr, char *data);
void tree_set_n(tree *tr, int n);
void tree_add(tree *tr);
void tree_free(tree *tr);
void tree_free_data(tree *tr);
void tree_free_n(tree *tr);

#endif
