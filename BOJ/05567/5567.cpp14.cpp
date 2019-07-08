#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, m, d[509], cnt=0;
bool check[509];
vector <vector<int>> r;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	r.resize(n+9);
	for(int i = 0; i<m; i++)
	{
		int t1, t2;cin>>t1>>t2;
		r[t1].push_back(t2);
		r[t2].push_back(t1);
	}
	for(auto p : r[1])
	{
		check[p]=true;
		if(r[p].empty())continue;
		for(auto t : r[p])check[t]=true;
	}
	for(int i = 2; i<=n; i++)if(check[i])cnt++;
	cout<<cnt;
	return 0;
}