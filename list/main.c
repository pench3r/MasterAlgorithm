#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static void print_list(List *list)
{
	ListElmt *element;
	int *data,i;
	i = 0;
	element = list_head(list);
	fprintf(stdout, "-> List size is %d\n", list_size(list));
	while (1)
	{
		data = list_data(element);
		fprintf(stdout, "-> List[%d] is %d\n", i, *data);
		if (list_is_tail(element))
		{
			break;
		} else {
			element = list_next(element);
		}
		i++;
	}
	return;
}

int main(int argc, char *argv[])
{
	List list;
	ListElmt *element;
	int *data, i;
	list_init(&list, free);
	element = list_head(&list);
	
	// init linked list	
	for (i=10; i > 0; i--)
	{
		if ((data = (int *)malloc(sizeof(int))) == NULL) return 1;
		*data = i;
		if (list_ins_next(&list, NULL, data) != 0) return 1;
	}
	print_list(&list);
	element = list_head(&list);
	for (i=0; i < 7; i++)
	{
		element = list_next(element);
	}
	data = list_data(element);
	fprintf(stdout, "removing an element after the one containing %03d\n", *data);
	if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
	fprintf(stdout, "remove the data of element is %03d\n", *data);
	free(data);
	element = list_head(&list);
	element = list_next(element);
	element = list_next(element);
	fprintf(stdout, "insert an element after the one containing %03d\n", *(int *)(list_data(element)));
	data = (int *)malloc(sizeof(int));
	*data = 29;
	if (list_ins_next(&list, element, data) != 0) return 1;
	fprintf(stdout, "continue insert...");
	data = (int *)malloc(sizeof(int));
	*data = 39;
	if (list_ins_next(&list, element, data) != 0) return 1;
	print_list(&list);
	fprintf(stdout, "removing an element after the one containing %03d\n", *(int *)(list_data(element)));
	if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
	free(data);
	print_list(&list);
	list_destory(&list);
	return 0;
}
