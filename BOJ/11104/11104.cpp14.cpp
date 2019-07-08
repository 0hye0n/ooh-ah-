#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		char data[30];
		lld result = 0, temp = 1;
		scanf("%s", data);
		for(int j = 23; j>=0; j--)
		{
			result +=(data[j]-'0')*temp;
			temp*=2;
		}
		printf("%lld\n", result);
	}
	return 0;
}