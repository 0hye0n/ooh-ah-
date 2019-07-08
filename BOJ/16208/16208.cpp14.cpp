#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, data[500009];
lld res = 0, sum=0;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		scanf(" %d", &data[i]);
		sum+=data[i];
	}
	for(int i = 0; i<n-1; i++)
	{
		sum-=data[i];
		res += data[i]*sum;
	}
	printf("%d", res);
	return 0;
}