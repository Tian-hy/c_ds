#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequeue.h"

sequeue *sequeue_create(){
	sequeue *sq;
	if ((sq = (sequeue *)malloc(sizeof(sequeue))) == NULL){
		return NULL;
	}
	memset(sq->data, 0, sizeof(sq->data));
	sq->front = sq->rear = 0;
	return sq;
}

int sequeue_enqueue(sequeue *sq, data_t x){
	if (sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	if ((sq->rear+1)%N == sq->front){
		printf("sqeueue is full\n");
		return -1;
	}
	sq->data[sq->rear] = x;
	sq->rear = (sq->rear+1) % N;
	return 0;
}

data_t sequeue_dequeue(sequeue *sq){
	if (sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	data_t data;
	data = sq->data[sq->front];
	sq->front = (sq->front+1)%N;
	return data;
}

int sequeue_empty(sequeue *sq){
	if (sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	return sq->front == sq->rear;
}

int sequeue_full(sequeue *sq){
	if (sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	return (sq->rear+1)%N == sq->front;
}

int sequeue_clear(sequeue *sq){
	if (sq == NULL){
		printf("sq is NULL\n");
		return -1;
	}
	sq->front = sq->rear = 0;
	return 0;
}

sequeue *sequeue_free(sequeue *sq){
	if (sq == NULL){
		printf("sq is NULL\n");
		return NULL;
	}
	free(sq);
	sq = NULL;
	return NULL;
}

