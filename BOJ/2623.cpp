#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, indegree[1009] = {0};

vector<vector<int>> v;
stack <int> res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	v.resize(n + 1);

	for(int i = 0; i < m; i++)
	{
		int selected_num; cin>>selected_num;

		if(selected_num == 0) continue;
		
		int cur, pre; cin>>cur;

		for(int j = 1; j < selected_num; j++)
		{
			cin>>pre;
			v[pre].push_back(cur);
			indegree[cur]++;
			cur = pre;
		}
	}

	queue <int> q;

	for(int i = 1; i <= n; i++)
		if(indegree[i] == 0) q.push(i);

	for(int i = 1; i <= n; i++)
	{
		if(q.empty())
		{
			cout<<"0";
			return 0;			
		}

		int current = q.front();
		res.push(current);

		q.pop();

		for(auto p : v[current])
		{
			indegree[p]--;
			if(indegree[p] == 0) q.push(p);
		}
	}

	while(!res.empty())
	{
		cout<<res.top()<<"\n";
		res.pop();
	}

	return 0;
}