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
}

int main(int argc, char *argv[])
{
	List list;
	ListElmt *element;
	int *data, i;
	char *mes;
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
	mes = "This is string";
	if (list_ins_next(&list, element, mes) != 0) return 1;
	element = list_next(element);
	mes = list_data(element);
	fprintf(stdout, "removing an element after the one containing %s\n", mes);
	if (list_rem_next(&list, element, (void **)&data) != 0) return 1;
	fprintf(stdout, "the data is %03d\n", *data);
	element = list_head(&list);
	element = list_next(element);
	element = list_next(element);
	*data = 9999;
	if (list_ins_next(&list, element, data) != 0) return 1;
	print_list(&list);
	list_destory(&list);
	return 0;
}
