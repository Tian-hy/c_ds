typedef int data_t;

typedef struct{
	data_t *data;
	int maxlen;
	int top; //栈顶的位置
}sqstack;

sqstack *sqstack_create(int len);
int sqstack_push(sqstack *s, int value);
data_t sqstack_pop(sqstack *s);
data_t sqstack_top(sqstack *s);
int sqstack_clear(sqstack *s);
int sqstack_free(sqstack *s);
int sqstack_empty(sqstack *s); // if the stack is empty, return True
int sqstack_full(sqstack *s);
