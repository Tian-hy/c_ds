#ifndef _HASH_H_
#define _HASH_H_

#define N 15

typedef int data_t;
typedef struct node{
	data_t key;
	data_t value;
	struct node *next;
}listnode, *linklist;

typedef struct{
	listnode data[N];
}hash;

hash *hash_create();
int hash_append(hash *ht, data_t key);
linklist hash_search(hash *ht, data_t key);

#endif
