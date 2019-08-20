#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;


int t, n, cost[1009], res[1009], in[1009];
vector <vector<int>> v;

void solve()
{


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;


	while(t--)
	{
		int k, ans;cin>>n>>k;
		v.resize(n + 1);

		for(int i = 1; i <= n; i++)cin>>cost[i];
		for(int i = 0; i < k; k++)
		{
			int x, y;cin>>x>>y;
			v[x].push_back(y);
			in[y]++;
		}
		cin>>ans;
		solve();
		cout<<res[ans]<<"\n";
		v.clear();
	}		
	return 0;
}