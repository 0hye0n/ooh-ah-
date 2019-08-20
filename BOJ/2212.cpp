#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k, sensor[10009], diff[10009], mn = 0;

vector <pair<int, int>> line;
vector <int> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(int i = 0; i < n; i++)cin>>sensor[i];


	sort(sensor, sensor + n);
	
	if(k == 1)
	{
		cout<<sensor[n - 1] - sensor[0];
		return 0;
	}

	if(n <= k)
	{
		cout<<"0";
		return 0;
	}

	for(int i = 1; i < n; i++)
	{
		diff[i] = sensor[i] - sensor[i - 1];
		line.push_back(make_pair(diff[i], i));
	}

	sort(line.begin(), line.end(), greater<pair<int, int>>());

	for(int i = 0; i < k - 1; i++) ans.push_back(line[i].second);
	sort(ans.begin(), ans.end());

	mn = sensor[ans[0] - 1] - sensor[0] + sensor[n - 1] - sensor[ans[k - 2]];

	for(int i = 1; i < k - 1; i++)
	{
		mn += sensor[ans[i] - 1] - sensor[ans[i - 1]];
	}

	cout<<mn;


	return 0;
}