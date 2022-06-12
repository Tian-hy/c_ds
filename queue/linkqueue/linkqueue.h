typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}listnode, *linklist;

typedef struct {
	linklist front;
	linklist rear;
}linkqueue;

linkqueue *create();
int enqueue(linkqueue *lq, data_t x);
data_t dequeue(linkqueue *lq);
int empty(linkqueue *lq);
int clear(linkqueue *lq);
linkqueue *queue_free(linkqueue *lq);
