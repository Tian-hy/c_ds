typedef int data_t;

typedef struct{
	data_t *data;
	int maxlen;
	int top; //栈顶的位置
}sqstack;

sqstack *create(int len);
int push(sqstack *s, int value);
data_t pop(sqstack *s);
data_t top(sqstack *s);
int clear(sqstack *s);
int stack_free(sqstack *s);
int empty(sqstack *s); // if the stack is empty, return True
int full(sqstack *s);
