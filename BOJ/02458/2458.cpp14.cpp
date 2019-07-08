#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, m, cnt[509], ans=0;
vector <vector<int>> st;
bool check[509];
void solve(int pos, int data)
{
	for(auto p : st[pos])
	{
		
		if(check[p])continue;
		cnt[data]++;
		cnt[p]++;
		check[p]=true;
		solve(p, data);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cin>>n>>m;
	st.resize(n+9);
		
	for(int i = 1; i<=m; i++)
	{
		int x, y;cin>>x>>y;
		st[x].push_back(y);
	}
	for(int i = 1; i<=n; i++){memset(check, false, sizeof(check));solve(i, i);}
	for(int i = 1; i<=n; i++)if(cnt[i]==n-1)ans++;
	cout<<ans;
	return 0;
}