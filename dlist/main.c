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
	int *data, *data1;
	dlist_init(&dlist, free);
	for (int i=10; i > 0; i--)
	{
		if ((data = (int *)malloc(sizeof(int))) == NULL) return 1;
		*data = i;
		if (dlist_ins_next(&dlist, NULL, data) != 0) return 0;
		free(data);
	}
	print_dlist(&dlist);
	delement = dlist_head(&dlist);
	delement = dlist_next(delement);
	delement = dlist_next(delement);
	data = dlist_data(delement);
	fprintf(stdout, "three data is %d\n", *data);
	data1 = (int *)malloc(sizeof(int));
	*data1 = 133;
	fprintf(stdout, "insert a element after containg %d.\n", *data);
	dlist_ins_next(&dlist, delement, data1);
	print_dlist(&dlist);
	*data1 = 222;
	fprintf(stdout, "insert a element before containg %d.\n", *data);
	dlist_ins_prev(&dlist, delement, data1);
	print_dlist(&dlist);
	// dlist_remove(&dlist, delement, (void **)&data1);
	// fprintf(stdout, "remove a element that containg %d.\n", *data1);
	// print_dlist(&dlist);
	dlist_destory(&dlist);
	free(data1);
	return 0;
}	
