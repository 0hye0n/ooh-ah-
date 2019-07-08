#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int t, n;
int dp[19];
int main()
{
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i<=10; i++)dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	while(t--)
	{
		scanf(" %d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}