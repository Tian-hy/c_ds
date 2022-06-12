#include <stdio.h>
#include "sqstack.h"

int main(int argc, char *argv[]){
	sqstack *s;
	s = create(100);
	if (s==NULL)
		return -1;

	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	while(!empty(s)){
		printf("pop: %d\n", pop(s));
	}
	stack_free(s);
}
