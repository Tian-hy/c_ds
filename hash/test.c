#include <stdio.h>
#include "hash.h"

int main(int argc, const char *argv[]){
	hash *ht;
	data_t data[] = {12, 32, 43, 14, 16, 61, 1, 53, 20, 21, 5};
	int i;
	data_t key;
	linklist r;

	if ((ht = hash_create()) == NULL)
		return -1;

	for (i = 0; i<sizeof(data)/sizeof(data_t); i++){
		hash_append(ht, data[i]);
	} 

	printf("search: ");
	scanf("%d", &key);
	r = hash_search(ht, key);
	if (r == NULL)
		printf("NOT FOUND\n");
	else
		printf("FOUND: %d %d\n", key, r->key);
}

