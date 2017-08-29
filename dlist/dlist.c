#include "dlist.h"
#include <stdio.h>
#include <string.h>

void dlist_init(Dlist *dlist, void (*destory)(void *data))
{
	dlist->size = 0;
	dlist->destory = destory;
	dlist->head = NULL;
	dlist->tail = NULL;
}

/* if dlist is empty, dlist->head = dlist->tail = new_dlistelement;else dlistelement is NULL,
 * insert new_dlistelement to dlist->head prev, otherwise normal insert
 */
int dlist_ins_prev(Dlist *dlist, DlistElmt *dlistelement, const void *data)
{
	DlistElmt *new_dlistelement;
	new_dlistelement = (DlistElmt *)malloc(sizeof(DlistElmt));
	new_dlistelement->data = (void *)malloc(sizeof(int));
	memcpy(new_dlistelement->data, data, sizeof(int));
	new_dlistelement->prev=new_dlistelement->next=NULL;
	if (dlist_size(dlist) == 0)
	{
		dlist->head = dlist->tail = new_dlistelement;
		dlist->size++;
		return 0;
	}
	if (dlistelement == NULL || dlistelement->prev == NULL)
	{
		new_dlistelement->next = dlist->head;
		dlist->head->prev = new_dlistelement;
		dlist->head = new_dlistelement;		
	} else {
		dlistelement->prev->next = new_dlistelement;
		new_dlistelement->prev = dlistelement->prev;
		new_dlistelement->next = dlistelement;	
		dlistelement->prev = new_dlistelement;
	}
	dlist->size++;
	return 0;	
}

int dlist_ins_next(Dlist *dlist, DlistElmt *dlistelement, const void *data)
{
	DlistElmt *new_dlistelement = (DlistElmt *)malloc(sizeof(DlistElmt));
	new_dlistelement->prev = new_dlistelement->next = NULL;
	new_dlistelement->data = (void *)malloc(sizeof(int));
	memcpy(new_dlistelement->data, data, sizeof(int));
	if (dlist_size(dlist) == 0)
	{
		dlist->head = dlist->tail = new_dlistelement;
		dlist->size++;
		return 0;
	}
	if (dlistelement == NULL || dlistelement->next == NULL)
	{
		new_dlistelement->prev = dlist->tail;
		dlist->tail->next = new_dlistelement;
		dlist->tail = new_dlistelement;
	} else {
		new_dlistelement->prev = dlistelement;
		new_dlistelement->next = dlistelement->next;
		dlistelement->next->prev = new_dlistelement;
		dlistelement->next = new_dlistelement;
	}
	dlist->size++;
	return 0;
}
	
int dlist_remove(Dlist *dlist, DlistElmt *dlistelement, void **data)
{
	if (dlist_size(dlist) == 0 || dlistelement == NULL) return 1;
	*data = dlistelement->data;
	if (dlist_size(dlist) == 1)
	{
		dlist->tail = dlist->head = NULL;
		free(dlistelement);	
		dlist->size--;
		return 0;
	}
	if (dlistelement->prev == NULL)
	{
		dlistelement->next->prev = NULL;
		dlist->head = dlistelement->next;
	} else if (dlistelement->next == NULL) {
		dlistelement->prev->next = NULL;
		dlist->tail = dlistelement->prev;
	} else {
		dlistelement->prev->next = dlistelement->next;
		dlistelement->next->prev = dlistelement->prev;
	}
	free(dlistelement);
	dlist->size--;
	return 0;
}

void dlist_destory(Dlist *dlist)
{
	void *data;
	while (dlist_size(dlist) > 0)
	{
		if (dlist_remove(dlist, dlist_tail(dlist), (void **)&data) == 0)
		{
			dlist->destory(data);
		}
	}
	memset(dlist, 0, sizeof(Dlist));
	return;
}	
		
