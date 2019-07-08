#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld mn = 2e15;int n, m;
bool check[1009];
vector <vector<pair<int, int>>> v;
void solve(int start)
{
	lld sum=0;
	memset(check, false, sizeof(check));
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(auto p : v[start])pq.push(make_pair(p.second, p.first));
	check[start] = true;
	while(!pq.empty())
	{
		int cur = pq.top().second; 
		int cost = pq.top().first;
		pq.pop();
		if(check[cur])continue;
		check[cur]=true;
		sum+=cost;
		for(auto p : v[cur])
		{
			int next = p.first;
			int tcost = p.second;
			if(check[next])continue;
			pq.push(make_pair(tcost, next));
		}
	}
	mn = min(mn, sum);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n+9);
	for(int i = 0; i<m; i++)
	{
		int x, y, z;cin>>x>>y>>z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	solve(3);
	cout<<mn;
	return 0;
}