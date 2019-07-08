#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, dp[1000009];
int main()
{
	dp[1] = 0;
	scanf("%d", &n);
	for(int i = 2; i<=n; i++)
	{
		dp[i] = dp[i-1]+1;
		if(i%2==0&&dp[i]>dp[i/2]+1)dp[i] = dp[i/2]+1;
		if(i%3==0&&dp[i]>dp[i/3]+1)dp[i] = dp[i/3]+1;
	}
	printf("%d", dp[n]);
	return 0;
}