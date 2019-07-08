#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
lld data[309];
lld dp[309];
inline void solve(){
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i<=n; i++)cin>>data[i];
	dp[1] = data[1];
	dp[2] = data[1]+data[2];
	for(int i = 3; i<=n; i++)
	{
		dp[i] = max(data[i]+dp[i-2], data[i]+data[i-1]+dp[i-3]);
	}
	cout<<dp[n];
	return 0;
}