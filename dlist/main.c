#include "dlist.h"
#include <stdio.h>

static void print_dlist(Dlist *dlist)
{
	int *data, i;
	i = 0;
	DlistElmt *dlistelement;
	dlistelement = dlist_head(dlist);
	printf("Dlist -> size is [%d]\n", dlist_size(dlist));
	while (dlistelement)
	{
		data = dlist_data(dlistelement);
		dlistelement = dlist_next(dlistelement);
		printf("Dlist[%d] => %02d\n", i, *data);
		i++;
	}
}

int main(int argc, char *argv[])
{
	Dlist dlist;
	DlistElmt *delement;
	int *data;
	int *data1;
	dlist_init(&dlist, free);
	for (int i=10; i > 0; i--)
	{
		if ((data = (int *)malloc(sizeof(int))) == NULL) return 1;
		*data = i;
		if (dlist_ins_next(&dlist, NULL, data) != 0) return 0;
	}
	print_dlist(&dlist);
	delement = dlist_head(&dlist);
	delement = dlist_next(delement);
	delement = dlist_next(delement);
	data = dlist_data(delement);
	fprintf(stdout, "three data is %d\n", *data);
	data1 = (int *)malloc(sizeof(int));
	*data1 = 133;
	dlist_ins_next(&dlist, delement, data1);
	print_dlist(&dlist);
	*data1 = 222;
	dlist_ins_prev(&dlist, delement, data1);
	print_dlist(&dlist);
	dlist_destory(&dlist);
	return 0;
}	
