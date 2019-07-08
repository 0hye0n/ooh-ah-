#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int n;
long long ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector <pair<int, int>> data(n);
	for(int i = 0; i < n; i++)
	{
		cin>>data[i].first>>data[i].second;
	}

	sort(data.begin(), data.end());

	int left = data[0].first, right = data[0].second;
	for(int i = 1; i < n; i++)
	{
		if(data[i].first <= right) right = max(data[i].second, right);
		else
		{
			ans += right - left;
			left = data[i].first;
			right = data[i].second;
		}
	}
	ans += right - left;
	cout<<ans;
	return 0;
}