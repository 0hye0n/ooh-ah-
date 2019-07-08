#include <bits/stdc++.h>
using namespace std;
int n;
char data[69];
int main() 
{
	scanf(" %d", &n);
	while(n--)
	{
		scanf("%s", data);
		int len = strlen(data);
		int temp = data[len-1]-'0';
		if(temp%2==0)printf("even\n");
		else printf("odd\n");
	}
	return 0;
}