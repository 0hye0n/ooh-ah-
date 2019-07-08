#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char data[109];
int d = 'a'-'A';
int main()
{
	scanf("%s", data);
	int len  = strlen(data);
	for(int i = 0; i<len; i++)
	{
		if(data[i]>=97)data[i]-=d;
		else data[i]+=d;
	}
	printf("%s\n", data);
	return 0;
}