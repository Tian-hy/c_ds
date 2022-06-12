#include "tree.h"

typedef bitree *data_type;

typedef struct node{
	data_type data;
	struct node *next;
}listnode, *linklist;

typedef struct {
	linklist front;
	linklist rear;
}linkqueue;

linkqueue *create();
int enqueue(linkqueue *lq, data_type x);
data_type dequeue(linkqueue *lq);
int empty(linkqueue *lq);
int clear(linkqueue *lq);
linkqueue *queue_free(linkqueue *lq);
