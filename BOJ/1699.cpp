#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, dp[100009];

vector <int> v;

void init()
{
	for(int i = 1; i * i <= n; i++) v.push_back(i * i);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	init();

	int size = v.size();
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < size; j++)
		{
			if(v[j] > i)break;

			if(dp[i] == 0) dp[i] = i / v[j] + dp[i % v[j]];
			else dp[i] = min<int>(dp[i], i / v[j] + dp[i % v[j]]); 
		}
	cout<<dp[n];

	return 0;
}