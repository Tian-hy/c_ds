typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}listnode, *linklist;

typedef struct {
	linklist front;
	linklist rear;
}linkqueue;

linkqueue *linkqueue_create();
int linkqueue_enqueue(linkqueue *lq, data_t x);
data_t linkqueue_dequeue(linkqueue *lq);
int linkqueue_empty(linkqueue *lq);
int linkqueue_clear(linkqueue *lq);
linkqueue *linkqueue_free(linkqueue *lq);
