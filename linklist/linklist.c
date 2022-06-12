#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist create(){
	linklist header;
	header = (linklist)malloc(sizeof(listnode));
	if (header == NULL){
		printf("malloc failed\n");
	}
	header->data = 0;
	header->next = NULL;
	return header;
}

int append(linklist header, int value){ 
	if (header == NULL){
		printf("Header is NULL");
		return -1;
	}
	// new node
	linklist p, cur_node;
	if ((p = (linklist)malloc(sizeof(listnode))) == NULL){
		printf("malloc failed\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;
	
	//locate the tail of the list
	cur_node = header;
	while (cur_node->next != NULL)
		cur_node = cur_node->next;

	//insert
	cur_node->next = p;
	return 0;
}

linklist get_node(linklist header, int pos){
	linklist cur_node;
	if (header == NULL){
		printf("Header is NULL\n");
		return NULL;
	}
	cur_node = header;
	for (int i=-1; i<=pos; i++){
		if (pos == -1)
			return cur_node;
		if (cur_node->next == NULL){
			printf("Invalid position\n");
			return NULL;
		}
		else{
			if (pos == i)
				return cur_node;
			cur_node = cur_node->next;
		}
	}
	return NULL;
}

int insert(linklist header, data_t value, int pos){
	linklist node, new_node;
	node = get_node(header, pos-1);
	new_node = create();
	new_node->next = node->next;
	new_node->data = value;
	node->next = new_node;
	return 0;
}

int del(linklist header, int pos){
	if (header == NULL){
		printf("Header is NULL");
		return -1;
	}
	linklist node = get_node(header, pos-1);
	if (node == NULL){
		printf("Invalid position");
		return -1;
	}
	if (node->next == NULL){
		printf("Invalid position");
		return -1;
	}
	linklist next_node = node->next;
	node->next = node->next->next;
	free(next_node);
	next_node = NULL;
	return 0;
}

linklist del_every_node(linklist header){
	linklist node;
	if (header == NULL)
		return NULL;
	node = header;
	while (header != NULL){
		node = header;
		header = header->next;
		free(node);
	}
	return NULL;
}

int show(linklist header){
	linklist p;
	if (header == NULL) {
		printf("Header is NULL\n");
		return -1;
		}
	p = header;

	while (p->next != NULL){
		printf("%d ", p->next->data);
		p = p->next;
	}
	puts("");
	return 0;
}

int reverse(linklist header){
	if (header == NULL || header->next == NULL || header->next->next == NULL)
		return -1;
	linklist q, p = header->next->next;
	header->next->next = NULL;
	while (p != NULL){
		q = p;
		p = p->next;

		q->next = header->next;
		header->next = q;
	}
	return 0;
}

linklist list_free(linklist H) {
	linklist p;

	if (H == NULL)
		return NULL;

	p = H;

	printf("free:");
	while (H != NULL) {
		p = H;
		printf("%d ", p->data);
		H = H->next;
		free(p);
	}
	puts("");

	return NULL;
}

linklist adjmax(linklist header){
	linklist p, q, r;
	data_t sum;
	if (header == NULL){
		return NULL;
	}
	if (header->next == NULL || header->next->next == NULL || header->next->next->next == NULL)
		return header;

	q = header->next;
	p = header->next->next;
	r = q;
	sum = q->data + p->data;
	
	while (p->next != NULL){
		p = p->next;
		q = q->next;
		if (sum < q->data + p->data){
			sum = q->data + p->data;
			r = q;
		}
	}
	return r;
}

int merge(linklist header1, linklist header2){
	linklist p, q, r;
	if (header1 == NULL || header2 == NULL)
		return -1;
	p = header1->next;
	q = header2->next;
	r = header1;
	header1->next = NULL;
	header2->next = NULL;

	while( p && q){
		if (p->data <= q->data){
			r->next = p;
			p = p->next;
			r = r->next;
			r->next = NULL;
		}
		else{
			r->next = q;
			q = q->next;
			r = r->next;
			r->next = NULL;
		}
	}
	if (p == NULL){
		r->next = q;
	}
	else{
		r->next = p;
	}
	return 0;
}
