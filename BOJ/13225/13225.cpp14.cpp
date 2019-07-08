#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int c;
int main()
{
	scanf("%d", &c);
	while(c--)
	{
		int n, cnt=0;scanf(" %d", &n);
		for(int i = 1; i<=n; i++)if(n%i==0)cnt++;
		printf("%d %d\n", n, cnt);
	}
	return 0;
}