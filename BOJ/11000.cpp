#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector <pair<int, int>> v;
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		int s, t;cin>>s>>t;
		v.push_back(make_pair(s, t));
	}

	sort(v.begin(), v.end());

	pq.push(make_pair(v[0].second, v[0].first));
	ans = 1;

	for(int i = 1; i < n; i++)
	{
		while(!pq.empty() && pq.top().first <= v[i].first)pq.pop();

		pq.push(make_pair(v[i].second, v[i].first));

		int size = pq.size();
		ans = max<int>(size, ans);
	}

	cout<<ans;


	return 0;
}