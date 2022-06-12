#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

linkstack create(){
	linkstack s;

	s = (linkstack)malloc(sizeof(listnode));
	if (s == NULL){
		printf("malloc failed\n");
		return NULL;
	}
	s->data = 0;
	s->next = NULL;
	return s;
}

int push(linkstack s, int value){
	linkstack p;
	p = (linkstack)malloc(sizeof(listnode));
	if (s == NULL){
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = s->next;
	s->next = p;

	return 0;
}

data_t pop(linkstack s){
	linkstack p;
	data_t data;

	data = s->next->data;
	p = s->next;
	s->next = p->next;

	free(p);
	p = NULL;
	return data;
}

data_t top(linkstack s){
	return s->next->data;
}

int stack_free(linkstack s){
	int data;
	while(!empty(s)){
		data = pop(s);
		printf("free: %d\n", data);
	}
	free(s);
	return 0;
}

int empty(linkstack s){
	if (s == NULL){
		printf("s is NULL\n");
		return 0;
	}
	return s->next==NULL ? 1 : 0;
}

