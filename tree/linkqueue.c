#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

linkqueue *create(){
	linkqueue *lq;
	lq = (linkqueue *)malloc(sizeof(linkqueue));
	if (lq == NULL)
		return NULL;
	lq->front = lq->rear = (linklist)malloc(sizeof(listnode));
	if (lq->front == NULL)
		return NULL;

	lq->front->next = NULL;
	lq->front->data = 0;
	return lq;
}

int enqueue(linkqueue *lq, data_type x){
	linklist p;
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL){
		return -1;
	}
	p->data = x;
	p->next = NULL;
	lq->rear->next = p;
	lq->rear = p;
	return 0;
}

data_type dequeue(linkqueue *lq){
	linklist p;
	p = lq->front;
	lq->front = lq->front->next;
	free(p);
	p = NULL;
	return lq->front->data;
}

int empty(linkqueue *lq){
	return (lq->front == lq->rear);
}

int clear(linkqueue *lq){
	linklist p;
	while(lq->front != lq->rear){
		p = lq->front;
		lq->front = lq->front->next;
		free(p);
	}
	return 0;
}

linkqueue *queue_free(linkqueue *lq){
	linklist p;
	while(lq->front){
		p = lq->front;
		lq->front = lq->front->next;
		free(p);
	}
	free(lq);
	return NULL;
}
