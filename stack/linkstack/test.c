#include <stdio.h>
#include "linkstack.h"

int main(int argc, char *argv[]){
	linkstack s;
	s = create();
	if (s==NULL)
		return -1;

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	while(!empty(s)){
		printf("pop: %d\n", pop(s));
	}
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	stack_free(s);
}
