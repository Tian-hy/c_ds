#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

int main(int argc, char *argv[]){
	linkqueue *lq;
	sqstack *hour, * five_min, *one_min;
	int min = 0, val;

	if ((lq = linkqueue_create()) == NULL)
		return -1;
	for (int i = 1; i <= 27; i++){
		linkqueue_enqueue(lq, i);
	}
	
	if ((hour = sqstack_create(11)) == NULL){
		return -1;
	}
	if ((five_min = sqstack_create(11)) == NULL){
		return -1;
	}
	if ((one_min = sqstack_create(4)) == NULL){
		return -1;
	}

	while(1){
		min++;
		if (!linkqueue_empty(lq)){
			val = linkqueue_dequeue(lq);
			if (!sqstack_full(one_min))
				sqstack_push(one_min, val);
			else{
				while(!sqstack_empty(one_min)){
					linkqueue_enqueue(lq, sqstack_pop(one_min));
				}
				if (!sqstack_full(five_min))
					sqstack_push(five_min, val);
				else{
					while(!sqstack_empty(five_min)){
						linkqueue_enqueue(lq, sqstack_pop(five_min));
					}
					if (!sqstack_full(hour))
						sqstack_push(hour, val);
					else{
						while(!sqstack_empty(hour)){
							linkqueue_enqueue(lq, sqstack_pop(hour));
						}
						linkqueue_enqueue(lq, val); // 00:00
						break;
					}
				}
			}
		}
	}
	printf("total min: %d\n", min);

	return 0;
}
