#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t, data[30];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int n;scanf(" %d", &n);
		for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
		sort(data, data+n);
		printf("%d\n", 2*(data[n-1]-data[0]));
	}
	return 0;
}