#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, indegree[1009], mx[1009], cnt[1009], strahler[1009];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		vector<vector<int>> v;
		int k, m, p;
		v.resize(m + 1);

		for(int i = 0; i < p; i++)
		{
			int a, b;cin>>a>>b;
			v[a].push_back(b);
			indegree[b]++;
		}

		queue <int> q;

		for(int i = 1; i <= m; i++)
		{
			if(indegree[i] == 0)
			{
				q.push(i);
				mx[i] = 1;
			}
		}

		for(int i = 1; i <= m; i++)
		{
			int cur = q.front();
			q.pop();


			for(auto p : v[cur])
			{
				
				indegree[p]--;
				if(indegree[p] == 0)q.push(p);
			}
		}
	}	
	return 0;
}