#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n, m, a1=0, a2=0, b1=0, b2=0, c1=0, c2=0;
void solve(){
	lld temp = n-m;
	for(lld i = 2; i<=n; i*=2) a1+=n/i;
	for(lld i = 5; i<=n; i*=5) a2+=n/i;
	for(lld i = 2; i<=m; i*=2) b1+=m/i;
	for(lld i = 5; i<=m; i*=5) b2+=m/i;
	for(lld i = 2; i<=temp; i*=2) c1+=temp/i;
	for(lld i = 5; i<=temp; i*=5) c2+=temp/i;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	solve();

	cout<<min(a1-b1-c1, a2-b2-c2);
	return 0;
}