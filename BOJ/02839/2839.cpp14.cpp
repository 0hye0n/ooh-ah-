#include <bits/stdc++.h>

using namespace std;

char data[101];

int main() {
	int n, temp, k=0;
	scanf("%d", &n);
	temp = n/5;
	for(int i = temp, j=(n%5)/3; i>=0; i--)
	{
			if((n%5+5*k)%3==0)
			{
				printf("%d", i+j);
				break;
			}
			k++;
			j=((n%5)+5*k)/3;
	}
	if(k==temp+1)
		printf("-1");
	
	return 0;
}
