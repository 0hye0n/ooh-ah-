#include <stdio.h>
int n, k;
int data[5];
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	int i, j;
	for(i = 0; i<4; i++)scanf(" %d", &data[i]);
	
	for(i = 0; i<4; i++)
		for(j = 1; j<4; j++)if(data[j-1]>data[j])swap(&data[j-1],&data[j]);
	
	printf("%d\n", data[0]*data[2]);
   return 0;
}