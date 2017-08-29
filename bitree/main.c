#include "bitree.h"
#include "../list/list.h"
#include <stdio.h>
#include <stdlib.h>

static void print_list(List *list);

int bitree_preorder(const BiTreeNode *node, List *list)
{
	if (!bitree_is_eob(node))
	{
		if (list_ins_next(list, list_tail(list), bitree_data(node)) != 0) return -1;
		if (!bitree_is_eob(bitree_left(node)))
		{
			if (bitree_preorder(bitree_left(node), list) != 0) return -1;
		}
		if (!bitree_is_eob(bitree_right(node)))
		{
			if (bitree_preorder(bitree_right(node), list) != 0) return -1;
		}
	}
	return 0;
}

static void print_tree(const BiTree *tree)
{
	List list;
	list_init(&list, free);
	bitree_preorder(bitree_root(tree), &list);
	print_list(&list);
	list_destory(&list);
	return;
}

static void print_list(List *list)
{
	ListElmt *element;
	int *data, i;
	i = 0;
	element = list_head(list);
	fprintf(stdout, "List => size is [%d].\n", list_size(list));
	while (element)
	{
		data = (int *)list_data(element);
		fprintf(stdout, "List[%d] ---> %02d.\n", i, *data);	
		element = list_next(element);
		i++;
	}	
}

static int insert_int(BiTree *tree, int i)
{
	BiTreeNode *node, *prev = NULL;
	int direction, *data;
	node = tree->root;
	direction = 0;
	while (!bitree_is_eob(node))
	{
		prev = node;
		if ( i == *(int *)bitree_data(node)) return -1;
		if (i < *(int *)bitree_data(node))
		{
			node = bitree_left(node);
			direction = 1;
		} else {
			node = bitree_right(node);
			direction = 2;
		}
	}
	if ((data = (int *)malloc(sizeof(int))) == NULL) return -1;
	*data = i;
	if (direction == 0) {
		bitree_ins_left(tree, NULL, data);
		free(data);
		return 0;
	}
	if (direction == 1) {
		bitree_ins_left(tree, NULL, data);
		free(data);
		return 0;
	}
	if (direction == 2) {
		bitree_ins_left(tree, NULL, data);
		free(data);
		return 0;
	}
	return -1;
	
}

static BiTreeNode *search_int(BiTree *tree, int i)
{
	BiTreeNode *node;
	node = bitree_root(tree);
	while (!bitree_is_eob(node))
	{
		if ( i == *(int *)bitree_data(node)) return node;
		if ( i < *(int *)bitree_data(node))
		{
			node = bitree_left(node);
		} else {
			node = bitree_right(node);
		}
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	BiTree tree;
	int i = 15;
	BiTreeNode *node;
	bitree_init(&tree, free);
	bitree_ins_left(&tree, NULL, &i);
	if (insert_int(&tree, 20) != 0) return -1;
	if (insert_int(&tree, 25) != 0) return -1;
	if (insert_int(&tree, 10) != 0) return -1;
	print_tree(&tree);
	node = bitree_root(&tree);
	printf("the data is %d.\n", *(int *)bitree_data(node));
	// fprintf(stdout, "remove a node tree...\n");
	// node = search_int(&tree, i);
	// fprintf(stdout, "Found a node is containing %02d.\n", *(int *)bitree_data(node));
	// bitree_rem_left(&tree, node);
	// print_tree(&tree);
	bitree_destory(&tree);
	return 0;
}
