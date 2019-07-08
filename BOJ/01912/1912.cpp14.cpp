#include <bits/stdc++.h>
#define MAX 100009
using namespace std;
typedef long long lld;
int n, data[MAX], dp[MAX];
lld mx = -100000009;
inline void solve(){
	for(int i = 1; i<=n; i++){
		dp[i] = data[i-1]+dp[i-1]>data[i-1]?data[i-1]+dp[i-1]:data[i-1];
		mx = mx<dp[i]?dp[i]:mx;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;dp[0] = 0;int cnt=0;
	for(int i = 0; i<n; i++)
	{
		cin>>data[i];
		if(data[i]<0)cnt++;
	}
	solve();
	cout<<mx;
	return 0;
}