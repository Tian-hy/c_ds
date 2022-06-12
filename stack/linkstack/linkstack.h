typedef int data_t;

typedef struct node{
	data_t data;
	struct node *next;
}listnode, *linkstack;

linkstack create();
int push(linkstack s, int value);
data_t pop(linkstack s);
data_t top(linkstack s);
int stack_free(linkstack s);
int empty(linkstack s); // if the stack is empty, return True
