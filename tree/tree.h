#ifndef _TREE_H_
#define _TREE_H_

typedef char data_t;

typedef struct node_t{
	data_t data;
	struct node_t *lchild, *rchild;
}bitree;

bitree *bitree_create();
void preorder(bitree *r);
void inorder(bitree *r);
void postorder(bitree *r);
void layerorder(bitree *r);

#endif
