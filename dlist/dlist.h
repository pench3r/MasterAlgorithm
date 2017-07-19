#ifndef __ALGORITHM_DLIST_H__
#define __ALGORITHM_DLIST_H__

#include <stdlib.h>

typedef struct DlistElmt_ {
	void *data;
	struct DlistElmt_ *prev;
	struct DlistElmt_ *next;
} DlistElmt;

typedef struct Dlist_ {
	int size;
	void (*destory)(void *data);
	DlistElmt *head;
	DlistElmt *tail;
} Dlist;

// the constructor of dlist
void dlist_init(Dlist *dlist, void (*destory)(void *data));

// the destructor of dlist
void dlist_destory(Dlist *dlist);

int dlist_ins_prev(Dlist *dlist, DlistElmt *dlistelement, const void *data);

int dlist_ins_next(Dlist *dlist, DlistElmt *dlistelement, const void *data);

#define dlist_size(dlist) ((dlist)->size)

#define dlist_head(dlist) ((dlist)->head)

#define dlist_tail(dlist) ((dlist)->tail)

#define dlist_next(delement) ((delement)->next)

#define dlist_data(delement) ((delement)->data)

int dlist_remove(Dlist *dlist, DlistElmt *dlelement, void **data);
#endif /* __ALGORITHM_DLIST_H__ */
