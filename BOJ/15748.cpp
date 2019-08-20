#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long l, n, f, b, ans = 0;
vector<pair<long long, long long>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>l>>n>>f>>b;
	v.resize(n + 1);

	for(int i = 0; i < n; i++)cin>>v[i].second>>v[i].first;
	
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	
	long long diff = f - b, cur = 0;

	//for(int i = 0; i < n; i++)cout<<v[i].first<<" "<<v[i].second<<"\n";	

	for(int i = 0; i < n; i++)
	{
		if(cur < v[i].second)
		{
			ans += (v[i].second - cur) * diff * v[i].first;
			cur = v[i].second;
		}
	}

	cout<<ans;
	return 0;
}