#include <stdio.h>
int odd[10];
int pos = 0;
int sum = 0;
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main() {
	int i, j;
	for(i = 0; i<7; i++)
	{
		int temp;scanf(" %d", &temp);
		if(temp%2==1)
		{
			odd[pos]=temp;
			pos++;
		}
	}
	if(pos==0){printf("-1\n");return 0;}
	for(i = 0; i<pos; i++)
		for(j = 1; j<pos; j++)if(odd[j-1]>odd[j])swap(&odd[j-1], &odd[j]);
	for(i = 0; i<pos; i++)sum+=odd[i];
	printf("%d\n%d\n", sum, odd[0]);
   return 0;
}