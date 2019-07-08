#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n, e, d1[809], d2[809], d3[809];
lld mn = 2e15;
vector <vector<pair<lld, lld>>> v;
void Dijkstra(lld *d, lld s)
{
	priority_queue <pair<lld, lld>, vector<pair<lld, lld>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	while(!pq.empty())
	{
		lld cost = pq.top().first;
		lld cur = pq.top().second;
		pq.pop();
		if(d[cur]!=-1)continue;
		d[cur] = cost;
		for(auto p : v[cur])
		{
			lld next = p.first;
			lld tcost = p.second+cost;
			if(d[next]!=-1)continue;
			pq.push(make_pair(tcost, next));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	memset(d3, -1, sizeof(d3));
	cin>>n>>e;
	v.resize(e+9);
	for(int i = 0; i<e; i++)
	{
		lld x, y, z;cin>>x>>y>>z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	lld v1, v2;cin>>v1>>v2;
	Dijkstra(d1, 1);
	Dijkstra(d2, v1);
	Dijkstra(d3, v2);
	bool flag = false;
	if(d1[v1]!=-1&&d2[v2]!=-1&&d3[n]!=-1)
	{
		if(mn>d1[v1]+d2[v2]+d3[n])
		{
			mn = d1[v1]+d2[v2]+d3[n];
			flag = true;	
		}
		
	}
	if(d1[v2]!=-1&&d2[n]!=-1&&d3[v1]!=-1)
	{
		if(mn>d1[v2]+d2[n]+d3[v1])
		{
			mn = d1[v2]+d2[n]+d3[v1]; 
			flag = true;
		}
	}
	if(flag)cout<<mn;
	else cout<<"-1";
	return 0;
}