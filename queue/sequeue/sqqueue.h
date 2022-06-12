#define N 128

typedef int data_t;

typedef struct{
	data_t data[N];
	int front, rear;
}sequeue;

sequeue *sequeue_create();
int sequeue_enqueue(sequeue *sq, data_t x);
int sequeue_dequeue(sequeue *sq);
data_t sequeue_empty(sequeue *sq);
int sequeue_full(sequeue *sq);
int sequeue_clear(sequeue *sq);
sequeue *sequeue_free(sequeue *sq);
