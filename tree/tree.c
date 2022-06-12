#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "linkqueue.h"

bitree *bitree_create(){
	data_t ch;
	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	bitree *p;
	if ((p=(bitree *)malloc(sizeof(bitree))) == NULL){
		printf("malloc failed\n");
		return NULL;
	}
	p->data = ch;
	p->lchild = bitree_create();
	p->rchild = bitree_create();
	return p;
}

void preorder(bitree *r){
	if (r == NULL){
		return;
	}
	printf("%c", r->data);
	preorder(r->lchild);
	preorder(r->rchild);
}

void inorder(bitree *r){
	if (r == NULL){
		return;
	}
	inorder(r->lchild);
	printf("%c", r->data);
	inorder(r->rchild);
}

void postorder(bitree *r){
	if (r == NULL){
		return;
	}
	postorder(r->lchild);
	postorder(r->rchild);
	printf("%c", r->data);
}


void layerorder(bitree *r){
	linkqueue *lq;
	if ((lq = create()) == NULL)
		return;

	if (r == NULL)
		return;
	printf("%c", r->data);
	enqueue(lq, r);
	while (!empty(lq)){
		r = dequeue(lq);
		if (r->lchild){
			printf("%c", r->lchild->data);
			enqueue(lq, r->lchild);
		}
		if (r->rchild){
			printf("%c", r->rchild->data);
			enqueue(lq, r->rchild);
		}
	}
}
