#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, pack = 2e9, ea = 2e9, ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(int i = 0; i < m; i++)
	{
		int t1, t2;cin>>t1>>t2;
		pack = min(pack, t1);
		ea = min(ea, t2);
	}
	
	while(n)
	{
		if(n >= 6)
		{
			ans += min(pack, ea * 6);
			n -= 6;
		}

		else
		{
			ans += min(pack, ea * n);
			n = 0;
		}
	}

	cout<<ans;
	return 0;
}