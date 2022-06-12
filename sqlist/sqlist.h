
typedef int data_t; // int could be any type
#define N 128 // N is the total length of the sqlist

typedef struct Sqlist_t{
	data_t data[N];
	int lastIdx;
}sqlist, *sqlink;

sqlink create();
int clear(sqlink l);
int empty(sqlink l);
int len(sqlink l);
int loc(sqlink l, data_t value);
int insert(sqlink l, data_t value, int pos);
int show(sqlink l);
int lFree(sqlink l);
int del(sqlink l, int pos);
int merge(sqlink l1, sqlink l2);
int purge(sqlink l);

