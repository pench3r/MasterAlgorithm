#include "bitree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void bitree_init(BiTree *tree, void (*destory)(void *data))
{
	tree->size = 0;
	tree->destory = destory;
	tree->root = NULL;
}

int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node;
	if (node == NULL && tree->root != NULL) return 1;
	if (node != NULL && node->left != NULL) return 1;
	new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	new_node->data = (void *)malloc(sizeof(int));
	memcpy(new_node->data, data, sizeof(int));
	new_node->left = new_node->right = NULL;
	if (bitree_size(tree) == 0 && node == NULL)
	{
		tree->root = new_node;
		tree->size++;
		return 0;
	}
	node->left = new_node;
	tree->size++;
	return 0;
}

int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node;
	if ( node->right != NULL) return 1;
	if (node == NULL && tree->root != NULL) return 1;
	new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode));
	new_node->data = (void *)malloc(sizeof(int));
	memcpy(new_node->data, data, sizeof(int));
	new_node->left = new_node->right = NULL;
	if (bitree_size(tree) == 0 && node == NULL)
	{
		tree->root = new_node;
		tree->size++;
		return 0;
	}
	node->right = new_node;	
	tree->size++;
	return 0;
}

int bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **pos;
	if (bitree_size(tree) == 0) return 1;
	if ( node == NULL)
	{	
		pos = &tree->root;
	} else {
		pos = &node->left;
	}
	
	if ( *pos != NULL)
	{
		bitree_rem_left(tree, *pos);
		bitree_rem_right(tree, *pos);
		if (tree->destory != NULL)
		{
			tree->destory((*pos)->data);
		}
		free(*pos);
		*pos = NULL;
		tree->size--;
		return 0;
	}		
	return 0;
}

int bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode *pos;
	if (bitree_size(tree) == 0) return 1;
	if ( node == NULL)
	{	
		pos = tree->root;
	} else {
		pos = node->right;
	}
	
	if ( pos != NULL)
	{
		bitree_rem_left(tree, pos);
		bitree_rem_right(tree, pos);
		if (tree->destory != NULL)
		{
			tree->destory(pos->data);
		}
		free(pos);
		tree->size--;
		return 0;
	}		
	return 0;
}

int bitree_merge(BiTree *merge, BiTree *left, BiTree *right, const void *data)
{
	bitree_init(merge, left->destory);
	bitree_ins_left(merge, NULL, data);	
	bitree_root(merge)->left = bitree_root(left);
	bitree_root(merge)->right = bitree_root(right);
	merge->size = merge->size + bitree_size(left) + bitree_size(right);
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;
	return 0;
}
	
void bitree_destory(BiTree *tree)
{
	bitree_rem_left(tree, NULL);
	memset(tree, 0, sizeof(BiTree));
	return;
}
