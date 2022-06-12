typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}listnode, *linklist;

linklist create();
int append(linklist header, int value); //the head of the list
linklist get_node(linklist header, int pos);
int insert(linklist header, data_t value, int pos);
int show(linklist header);
int del(linklist header, int pos);
linklist del_every_node(linklist header);
int reverse(linklist header);
linklist list_free(linklist header);
int merge(linklist header1, linklist header2);
