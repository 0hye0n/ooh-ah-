#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long dp[99], n, sum = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	dp[1] = 1;
	dp[2] = 1;
	sum = 1;
	for(int i = 3; i <= n; i++)
	{
		dp[i] = sum + 1;
		sum += dp[i - 1];
	}
	cout<<dp[n];
	return 0;
}