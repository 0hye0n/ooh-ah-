#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, s, arr[29], ans = 0;

int solve(int pos, int sum, bool check)
{
	int ret = 0;
	if(sum == s && check) ret++;

	if(pos == n - 1)
	{	
		if(sum + arr[pos] == s) ret++;

		return ret;
	}

	ret += solve(pos + 1, sum + arr[pos], true);
	ret += solve(pos + 1, sum, false);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>s;
	int sum = 0;
	for(int i = 0; i < n; i++)cin>>arr[i];

	cout<<solve(0, 0, false);
	return 0;
}