#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


hash *hash_create(){
	hash *ht;

	if((ht = (hash *) malloc(sizeof(hash))) == NULL)
		return NULL;
	memset(ht, 0, sizeof(hash));
	return ht;
}

int hash_append(hash *ht, data_t key){
	linklist p, q;
	if (ht == NULL){
		return -1;
	}
	
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL){
		return -1;
	}
	p->key = key;
	p->value = key % N;
	p->next = NULL;

	q = &(ht->data[key%N]);
	
	while(q->next && q->next->key < p->key){
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	return 0;
}

linklist hash_search(hash *ht, data_t key){
	linklist p;
	if (ht == NULL){
		return NULL;
	}
	p = &(ht->data[key%N]);
	while (p->next){
		if (p->next->key == key){
			return p->next;
		}
		p = p->next;
	}
	return NULL;
}
