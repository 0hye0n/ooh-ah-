#include <bits/stdc++.h>
using namespace std;
int n, data[11];
int main() {
	scanf("%d", &n);
	
	for(int i= 0; i<n; i++)
	{
		int a, b, temp, j=1;
		scanf(" %d %d", &a, &b);
		temp = a%10;data[0] = a%10;
		if(temp == 0)
		{
			printf("10\n");
			continue;
		}
		while(1)
		{
			temp = (temp*data[0])%10;
			if(temp == data[0])
				break;
			data[j] = temp;
			j++;
			
		}
		if(b%j==0)
		printf("%d\n", data[j-1]);
		else
		printf("%d\n", data[b%j-1]);
	}
	return 0;
}