#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, indegree[32009], res[32009];
priority_queue <int, vector<int>, greater<int>> pq;
vector<vector<int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n + 1);

	for(int i = 0; i < m; i++)
	{
		int a, b;cin>>a>>b;
		v[a].push_back(b);
		indegree[b]++;
	}

	for(int i = 1; i <= n; i++)
	{
		if(indegree[i] == 0)pq.push(i);
	}

	for(int i = 1; i <= n; i++)
	{
		int cur = pq.top();
		pq.pop();
		res[i] = cur;
		for(auto p : v[cur])
		{
			indegree[p]--;
			if(indegree[p] == 0)pq.push(p);
		}
	}

	for(int i = 1; i <= n; i++)cout<<res[i]<<" ";
	return 0;
}