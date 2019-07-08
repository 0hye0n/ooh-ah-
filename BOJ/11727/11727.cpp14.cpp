#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
lld dp[1009];
inline void solve(){
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	lld temp = 2;
	for(int i = 4; i<=1000; i++)
	{
		dp[i] = (dp[i-1]+2*dp[i-2])%10007;
	}
	cin>>n;
	cout<<dp[n];
	return 0;
}