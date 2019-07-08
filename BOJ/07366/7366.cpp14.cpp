#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n,cnt[100];
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i<=n; i++)
	{
		int t;char data[19];scanf("%d", &t);
		while(t--)
		{
			scanf(" %s", data);
			if(strcmp(data, "sheep")==0)cnt[i]++;
		}
	}
	for(int i = 1; i<=n; i++)printf("Case %d: This list contains %d sheep.\n\n", i, cnt[i]);
	return 0;
}