#include <bits/stdc++.h>
#define iMAX 0x7FFFFFFF
using namespace std;
typedef long long lld;

int v, e, s, d[20002];
vector <vector<pair<int, int>>> vt;

void Dijkstra()
{	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, s));
	while(!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if(d[cur] != -1)continue;
		d[cur] = cost;
		for(auto p : vt[cur]){
			int next = p.first;
			int acost = p.second + cost;
			if(d[next]!=-1)continue;
			pq.push(make_pair(acost, next));
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>v>>e>>s;
	vt.resize(v+1);
	for(int i = 0 ;i < e; i++){
		int u, v, w;cin>>u>>v>>w;
		vt[u].push_back({v, w});
	}
	memset(d, -1, sizeof(d));
	Dijkstra();
	for(int i = 1; i<=v; i++){
		if(d[i]==-1)cout<<"INF\n";
		else cout<<d[i]<<"\n";
	}
	return 0;
}