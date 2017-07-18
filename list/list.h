#ifndef __ALGORITHM_LIST_H__
#define __ALGORITHM_LIST_H__

#include <stdlib.h>

// node
typedef struct ListElmt_ {
	void *data;
	struct ListElmt_ *next;
} ListElmt;

// linked list
typedef struct List_ {
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destory)(void *data);
	ListElmt *head;
	ListElmt *tail;
} List;

// linked list init
void list_init(List *list, void (*destory)(void *data));

// linked list destructor
void list_destory(List *list);

// insert element to linked list
int list_ins_next(List *list, ListElmt *element, const void *data);

// remove element in linked list
int list_rem_next(List *list, ListElmt *element, void **data);

// acquire length of linked list
#define list_size(list) ((list)->size)
// acquire head of linked list
#define list_head(list) ((list)->head)
// acquire tail of linked list
#define list_tail(list) ((list)->tail)
// determine a element is head whether or not
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
// acquire data of the element in linked list
#define list_data(element) ((element)->data)
// acquire next element 
#define list_next(element) ((element)->next)
#endif /* __ALGORITHM_LIST_H__ */
