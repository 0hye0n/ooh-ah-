#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
long long n, dp[99][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n <= 2)
	{
		cout<<"1";
		return 0;
	}
	dp[0][0] = 2;
	dp[0][1] = 1;
	for(int i = 1; i < n; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}

	cout<<dp[n - 3][0];
	return 0;
}