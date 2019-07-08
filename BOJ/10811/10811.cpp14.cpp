#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, m;
int data[109];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)data[i]=i+1;
	for(int i = 0; i<m; i++)
	{
		int x, y;scanf(" %d %d", &x, &y);
		reverse(data+x-1, data+y);
	}	
	for(int i = 0; i<n; i++)printf("%d ", data[i]);
	return 0;
}