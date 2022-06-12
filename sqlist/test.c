#include <stdio.h>
#include "sqlist.h"

int main(int argc, char *argv[]){
	sqlink l, l1;
	l = create();
	if (l == NULL)
		return -1;
	insert(l, 10, 0);
	insert(l, 20, 0);
	insert(l, 20, 0);
	insert(l, 20, 0);
	insert(l, 20, 0);
	insert(l, 30, 0);
	insert(l, 40, 0);
	insert(l, 50, 0);
	insert(l, 60, 0);
	printf("l: \n");
	show(l);
	del(l, 0);
	printf("\ndel(l, 0): \n");
	show(l);
	l1 = create();
	if (l1 == NULL)
		return -1;
	insert(l1, 20, 0);
	insert(l1, 70, 0);
	insert(l1, 80, 0);
	printf("\nl1: \n");
	show(l1);
	merge(l, l1);
	printf("\nmerge(l, l1): \n");
	show(l);
	purge(l);
	printf("\npurge(l): \n");
	show(l);

	lFree(l);
	lFree(l1);
}
