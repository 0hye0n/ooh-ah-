#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, d='a'-'A';
char data[39];

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		scanf(" %[^\n]s", data);if(data[0]>=97)data[0]-=d;
		printf("%s\n", data);
	}
	return 0;
}