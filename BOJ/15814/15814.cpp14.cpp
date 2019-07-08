#include <bits/stdc++.h>
char data[109];
int n, x, y;

void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


int main() {
	scanf("%s", &data);
	scanf(" %d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf(" %d %d", &x, &y);
		swap(&data[x], &data[y]);
	}
	
	printf("%s", data);
	return 0;
}