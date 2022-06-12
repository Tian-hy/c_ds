#include <stdio.h>
#include <stdlib.h>

#define N 15

int quick_sort(int *data, int low, int high);
int partion(int *data, int low, int high); 
void show(int *data);
int compare(const void *p1, const void *p2);

int main(int argc, char *argv[]){
	int data[N] = {0};
	int i;

	srandom(10);

	for (i=0; i<N; i++){
		data[i] = random()%100;
	}

	show(data);
	quick_sort(data, 0, N-1);
	show(data);


	for (i=0; i<N; i++){
		data[i] = random()%100;
	}

	show(data);
	qsort(data, N, sizeof(int), compare); //调用
	show(data);
}

int quick_sort(int *data, int low, int high){
	int t;
	if (data == NULL){
		return -1;
	}
	if (low >= high)
		return 0;

	t = partion(data, low, high);
	quick_sort(data, low, t-1);
	quick_sort(data, t+1, high);
	return 0;
}

int partion(int *data, int low, int high){
	int temp = data[low];
	while(low < high){
		while (low < high && temp <= data[high])
			high--;
		data[low] = data[high];
		while (low < high && temp >= data[low]){
			low++;
		}
		data[high] = data[low];
	}
	data[low] = temp;
	return low;
}


void show(int *data){
	for (int i=0; i<N; i++){
		printf("%d ", data[i]);
	}
	puts("");
}

int compare(const void *p1, const void *p2){
	return (*(const int *)p1>*(const int *)p2);
}
