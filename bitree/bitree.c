#include "bitree.h"
#include <stdio.h>
#include <string.h>


void bitree_init(BiTree *tree, void (*destory)(void *data))
{
	tree->size = 0;
	tree->destory = destory;
	tree->root = NULL;
}

void bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node;
	new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	new_node->data = (void *)data;
	new_node->left = new_node->right = NULL;
	if (bitree_size(tree) == 0)
	{
		tree->root = new_node;
		tree->size++;
		return 0;
	}
