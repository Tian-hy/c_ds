#include <stdio.h>
#include "linkqueue.h"

int main(int argc, char *argv[]){
	linkqueue *lq;
	lq = create();
	if (lq == NULL)
		return -1;
	enqueue(lq, 1);
	enqueue(lq, 2);
	enqueue(lq, 3);
	enqueue(lq, 4);

	while (!empty(lq)){
		printf("dequeue: %d\n", dequeue(lq));
	}
	enqueue(lq, 1);
	enqueue(lq, 2);
	enqueue(lq, 3);
	enqueue(lq, 4);

	queue_free(lq);
}
