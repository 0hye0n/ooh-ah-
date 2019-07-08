#include <stdio.h>
int n, k, mx=0, temp=0;
int data[1009];
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++)scanf(" %d", &data[i]);
	for(i = 1; i<n; i++)
	{
		if(data[i]>data[i-1]){temp+=data[i]-data[i-1];if(mx<temp)mx=temp;}
		else temp=0;
	}
	printf("%d\n", mx);
   return 0;
}