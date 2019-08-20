#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, ans = 1;
vector <pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)
	{
		int s, e;cin>>s>>e;
		v.push_back(make_pair(e, s));
	}

	sort(v.begin(), v.end());
	
	int end = v[0].first;
	for(int i = 1; i < n; i++)
	{
		if(v[i].second >= end)
		{
			ans++;
			end = v[i].first;
		}
	}
	cout<<ans;
	return 0;
}