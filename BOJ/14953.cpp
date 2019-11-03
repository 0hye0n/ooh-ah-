#include <bits/stdc++.h>

using namespace std;

int indegree[100009], n, m, mn = 2e9, ans = -1;
bool check[100009];

vector<vector<int> > v;

void solve(int pos, int c)
{
	ans = max<int>(ans, pos + 1);
	if(pos == n) return;
	
	for(auto p : v[c])
	{
		if(check[p] || indegree[p] < indegree[c]) continue;
		check[p] = true;
		solve(pos + 1, p);
		check[p] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n + 1);
	for(int i = 0; i < m; i++)
	{
		int x, y;cin>>x>>y;
		indegree[x]++;
		indegree[y]++;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		if(indegree[i] == mn)
		{
			memset(check, false, sizeof(check));
			check[i] = true;
			solve(0, i);
		}
	}
	
	cout<<ans;
	
	
	
	return 0;
}