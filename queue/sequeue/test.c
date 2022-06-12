#include <stdio.h>
#include "sequeue.h"

int main(int argc, char *argv[]){
	sequeue *sq;
	sq = sequeue_create();
	if (sq == NULL)
		return -1;
	sequeue_enqueue(sq, 1);
	sequeue_enqueue(sq, 2);
	sequeue_enqueue(sq, 3);
	sequeue_enqueue(sq, 4);

	while (!sequeue_empty(sq)){
		printf("dequeue: %d\n", sequeue_dequeue(sq));
	}
	sequeue_enqueue(sq, 1);
	sequeue_enqueue(sq, 2);
	sequeue_enqueue(sq, 3);
	sequeue_enqueue(sq, 4);

	sequeue_free(sq);
}
