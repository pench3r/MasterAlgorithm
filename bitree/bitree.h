#ifndef __ALGORITHM_BITREE_H__
#define __ALGORITHM_BITREE_H__

#include <stdlib.h>

typedef struct BiTreeNode_ {
	void *data;
	struct BiTreeNode_ *left;
	struct BiTreeNode_ *right;
} BiTreeNode;

typedef struct BiTree_ {
	int size;
	int (*compare)(const void *key1, const void *key2);
	void (*destory)(void *data);
	BiTreeNode *root;
} BiTree;

void bitree_init(BiTree *tree, void (*destory)(void *data));

void bitree_destory(BiTree *tree);

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data);

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data);

int bitree_rem_left(BiTree *tree, BiTreeNode *node);

int bitree_rem_right(BiTree *tree, BiTreeNode *node);

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data);

#define bitree_size(tree) ((tree)->size)

#define bitree_is_eob(node) ((node) == NULL)

#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)

#define bitree_data(node) ((node)->data)

#define bitree_left(node) ((node)->left)

#define bitree_right(node) ((node)->right)

#define bitree_root(tree) ((tree)->root)

#endif /* __ALGORITHM_BITREE_H__ */
