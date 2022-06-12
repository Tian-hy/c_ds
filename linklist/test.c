#include <stdio.h>
#include "linklist.h"

int main(int argc, char *argv[]){
	/* linklist header, node; */
	/* int value; */
	/* header = create(); */
	/* if (header == NULL) */
	/* 	return -1; */
	/* while (1){ */
	/* 	printf("input: "); */
	/* 	scanf("%d", &value); */
	/* 	if (value < 0) */
	/* 		break; */
	/* 	append(header, value); */
	/* } */
	/* show(header); */
	/* node = get_node(header, 2); */
	/* if (node != NULL) */
	/* 	printf("%d \n", node->data); */
	/* insert(header, 10, 0); */
	/* printf("\ninsert 10 before pos 0\n"); */
	/* show(header); */
	/* printf("\ndel entry at pos 2\n"); */
	/* del(header, 2); */
	/* show(header); */
	/* printf("\nreverse  all entries\n"); */
	/* reverse(header); */
	/* show(header); */
	/* header = del_every_node(header); */
	/* printf("\ndel all entries\n"); */
	/* show(header); */
	linklist header1, header2;
	data_t a[] = {1, 3, 5, 6, 7, 9};
	data_t b[] = {2, 4, 5, 6, 8, 10};
	
	header1 = create();
	if (header1 == NULL)
		return 0;
	header2 = create();
	if (header2 == NULL)
		return 0;

	for (int i=0; i<sizeof(a)/sizeof(data_t); i++){
		append(header1, a[i]);
	}
	for (int i=0; i<sizeof(b)/sizeof(data_t); i++){
		append(header2, b[i]);
	}
	show(header1);
	show(header2);
	merge(header1, header2);
	show(header1);
	show(header2);
	list_free(header1);
	list_free(header2);
	return 0;
}
