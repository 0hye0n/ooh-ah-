#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k, coin[19], ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i = 0; i < n; i++)cin>>coin[i];

	for(int i = n - 1; i >=0; i--)
	{
		ans += k / coin[i];
		k %= coin[i];
	}	
	cout<<ans;
	return 0;
}