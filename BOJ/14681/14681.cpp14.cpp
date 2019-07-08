#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int x, y;
inline void solve()
{
	if(x<0)cout<<(y>0?"2":"3");
	else cout<<(y>0?"1":"4");
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y;
	solve();
	return 0;
}