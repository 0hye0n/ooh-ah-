#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, cost[509], indegree[509], res[509];
vector<vector<int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	v.resize(n + 1);
	for(int i = 0; i < n; i++)
	{
		cin>>cost[i + 1];
		int pre_build;cin>>pre_build;
		while(pre_build != -1)
		{
			indegree[i + 1]++;
			v[pre_build].push_back(i + 1);
			cin>>pre_build;
		}
		if(indegree[i + 1] == 0) res[i + 1] = cost[i + 1];
	}

	queue <int> q;
	
	for(int i = 1; i <=n; i++)
	{
		if(indegree[i] == 0) q.push(i);
	}


	for(int i = 1; i <= n; i++)
	{
		int cur = q.front();
		q.pop();

		for(auto p : v[cur])
		{
			res[p] = max<int>(res[p], res[cur] + cost[p]);
			indegree[p]--;
			if(indegree[p] == 0)q.push(p);
		}
	}

	for(int i = 1; i <= n; i++)cout<<res[i]<<"\n";
	return 0;
}