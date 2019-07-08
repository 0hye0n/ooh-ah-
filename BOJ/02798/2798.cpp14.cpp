#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, m, data[109];
int mx = 0, sum=0;
inline void solve(){
	for(int i = 0; i<n-2; i++)
	{
		sum+=data[i];
		for(int j = i+1; j<n-1; j++)
		{
			sum+=data[j];
			for(int k = j+1; k<n; k++)
			{
				sum+=data[k];
				if(sum<=m&&sum>mx)mx=sum;
				sum-=data[k];
			}
			sum-=data[j];
		}
		sum-=data[i];
	}
	cout<<mx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<n; i++)cin>>data[i];
	solve();
	return 0;
}