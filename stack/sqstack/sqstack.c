#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqstack.h"

sqstack *create(int len){
	sqstack *s;
	if ((s=(sqstack *)malloc(sizeof(sqstack))) == NULL){
		printf("malloc sqstack failed");
		return NULL;
	}
	if ((s->data = (data_t *)malloc(len *sizeof(data_t))) == NULL){
		printf("malloc data failed");
		return NULL;
	}
	memset(s->data, 0, len*sizeof(data_t));
	s->maxlen = len;
	s->top = -1;
	return s;
}

int push(sqstack *s, int value){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	if (s->top == s->maxlen-1){
		printf("stack is full\n");
		return -1;
	}
	s->top++;
	s->data[s->top] = value;
	return 0;
}

data_t pop(sqstack *s){
	int pop_data;
	pop_data = s->data[s->top];
	s->data[s->top] = 0;
	s->top--;
	return pop_data;
}

data_t top(sqstack *s){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	return s->data[s->top];
}

int clear(sqstack *s){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	s->top = -1;
	return 0;
}

int stack_free(sqstack *s){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	if (s->data != NULL)
		free(s->data);
	free(s);
	return 0;
}

int empty(sqstack *s){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	return s->top == -1?1:0;
}
int full(sqstack *s){
	if (s == NULL){
		printf("s is NULL\n");
		return -1;
	}
	return (s->top == s->maxlen-1?1:0);
}
