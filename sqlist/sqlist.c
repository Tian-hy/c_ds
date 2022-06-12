#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlist.h"

//需要申请内存，初始化，返回线性表的地址
sqlink create(){
	sqlink l;
	//malloc
	l = (sqlink)malloc(sizeof(sqlist));
	if (l==NULL){
		printf("Malloc failed\n");
		return l;
	}
	//init
	memset(l, 0, sizeof(sqlist));
	l->lastIdx = -1; //结构体指针访问成员
	
	//return 
	return l;
}

/*
 * @return 0-clear successfully, -1-failed
 */
int clear(sqlink l){
	if (l == NULL)
		return -1;
	memset(l, 0, sizeof(sqlist));
	l->lastIdx = -1;
	return 0;
}

/*
 * empty: Decide if the sqlist is an empyt list
 * para l:list
 * @return 1:empty, 0: not empyt
 */
int empty(sqlink l){
	if (l->lastIdx == -1)
		return 1;
	else
		return 0;
}

int len(sqlink l){
	if (l == NULL)
		return -1;
	return l->lastIdx+1;
}

int loc(sqlink l, data_t value){
	for (int i = 0; i <= l->lastIdx; i++) {
		if (l->data[i] == value)
			return i;
	}

	return -1;
}

int insert(sqlink l, data_t value, int pos){
	// if this is a full list
	if (l->lastIdx == N-1){
		printf("Not enough space for this entry\n");
		return -1;
	}

	// check if this is a valid position
	if (pos < 0||pos > l->lastIdx+1){
		printf("Invalid position\n");
		return -1;
	}

	//move
	for (int i = l->lastIdx; i >= pos; i--){
		l->data[i+1] = l->data[i];
	}

	//insert entry and lastIdx ++
	l->data[pos] = value;
	l->lastIdx++;
	return 0;
}

int show(sqlink l){
	if (l == NULL)
		return -1;

	for (int i = 0; i<= l->lastIdx; i++){
		printf("%d ", l->data[i]); 
	}
	puts("");
	return 0;
}

int lFree(sqlink l){
	if (l == NULL)
		return -1;
	free(l);
	l = NULL;
	return 0;
}

int del(sqlink l, int pos){
	if (l->lastIdx == -1){
		printf("This is an empty list\n");
		return -1;
	}

	if (pos < 0 || pos > l->lastIdx){
		printf("Invalid position\n");
		return -1;
	}

	for (int i=pos; i<=l->lastIdx-1; i++){
		l->data[i] = l->data[i+1];
	}

	l->data[l->lastIdx] = 0;
	l->lastIdx--;
	return 0;
}

int merge(sqlink l1, sqlink l2){
	int i = 0, idx;
	while(i <= l2->lastIdx){
		idx = loc(l1, l2->data[i]);
		if (idx == -1){
			if (insert(l1, l2->data[i], l1->lastIdx+1) == -1)
				return -1;
		}
		i++;
	}
	return 0;
}

int purge(sqlink l){
	int i = 1, j;
	if (l->lastIdx == 0)
		return 0;
	while (i <= l->lastIdx){
		j = i-1;
		while (j >= 0) {
			if (l->data[i] == l->data[j]){
				del(l, i);
				break;
			}
			else
				j--;
		}

		if (j < 0){
			i++;
		}
	}
	return 0;
}
