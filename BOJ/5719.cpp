#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> v;
int cost_d1[509], cost_d[509], n, m, s, d;

void Dijkstra(int start)
{
	memset(cost_d, -1, sizeof(cost_d));
	cost_d[start] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for(auto p : v[start]) pq.push(make_pair(p.second, p.first));

	while(!pq.empty())
	{
		int curx = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if(cost_d[curx] != -1)continue;
		cost_d[curx] = cost;
		for(auto p : v[curx])
		{
			int n_cost = cost + p.second;
			int next_x = p.first;

			if(cost_d[next_x] != -1) continue;

			pq.push(make_pair(n_cost, next_x));
		}
	}
}

void Dijkstra_extra(int start)
{
	memset(cost_d1, -1, sizeof(cost_d1));
	cost_d1[start] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for(auto p : v[start]) pq.push(make_pair(p.second, p.first));

	while(!pq.empty())
	{
		int curx = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if(cost_d1[curx] != -1 || curx == d)continue;
		cost_d1[curx] = cost;
		for(auto p : v[curx])
		{
			int n_cost = cost + p.second;
			int next_x = p.first;

			if(cost_d1[next_x] != -1 || next_x == d) continue;

			pq.push(make_pair(n_cost, next_x));
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;

	while(n != 0 && m != 0)
	{
		cin>>s>>d;
		v.resize(n + 1);
		for(int i = 0; i < m; i++)
		{
			int x, y, z;cin>>x>>y>>z;
			v[x].push_back(make_pair(y, z));
		}
		Dijkstra(s);
		Dijkstra_extra(s);
		for(int i = 0; i < n; i++)cout<<cost_d1[i]<<" ";
		cout<<"\n";
		v.clear();
		cin>>n>>m;
	}

	




	return 0;
}