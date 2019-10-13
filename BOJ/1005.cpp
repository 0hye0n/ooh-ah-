#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, dp[1009], cost[1009], indegree[1009];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		vector<vector<int>> v;
		memset(indegree, 0, sizeof(indegree));
		memset(dp, 0, sizeof(dp));
		memset(cost, 0, sizeof(dp));

		int n, k, w;cin>>n>>k;
		v.resize(n + 1);
		for(int i = 1; i <= n; i++) cin>>cost[i];

		for(int i = 0; i < k; i++)
		{
			int x, y;cin>>x>>y;
			v[x].push_back(y);
			indegree[y]++;
		}
		cin>>w;

		queue <int> q;

		for(int i = 1; i <= n; i++)
		{
			if(indegree[i] == 0)
			{
				q.push(i);
				dp[i] = cost[i];
			}
		}

		for(int i = 1; i <= n; i++)
		{
			int cur = q.front();
			q.pop();

			if(cur == w)
			{
				cout<<dp[cur]<<"\n";
				break;
			}

			for(auto p : v[cur])
			{
				dp[p] = max<int>(dp[p], dp[cur] + cost[p]);
				indegree[p]--;
				if(indegree[p] == 0)q.push(p);
			}
		}
	}

	return 0;
}