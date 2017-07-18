#include "list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAXSIZE 100
// void list_destructor(void *data)
void list_init(List *list, void (*destory)(void *data))
{
	list->size = 0;
	list->destory = destory;
	list->head = NULL;
	list->tail = NULL;
}		

void list_destory(List *list)
{
	ListElmt *element;
	void *data;
	while (list_size(list) > 0)
	{
		if (list_rem_next(list, list_head(list), (void **)&data) == 0)
			list->destory(data);
	}
	memset(list, 0, sizeof(List));
	return;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
	ListElmt *old_element;
	if (element == NULL)
	{
		*data = list->head->data;
		old_element = list->head;
		list->head = list->head->next;
		if (list_size(list) == 1)
		{
			list->tail = NULL;
		}
	} else {
		if (element->next == NULL) return -1;
		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;
		if(element->next == NULL)
		{
			list->tail = element;
		}
	}

	free(old_element);
	list->size--;
	return 0;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element;
	if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL) return -1;
	new_element->data = (void *)data;
	if (element == NULL)
	{
		new_element->next = list->head;
		list->head = new_element;
		if (list_size(list) == 0)
		{
			list->tail = new_element;
		}
	} else {
		new_element->next = element->next;	
		element->next = new_element;
		if (new_element->next == NULL)
		{
			list->tail = new_element;
		}
	}
	list->size++;
	return 0;
}