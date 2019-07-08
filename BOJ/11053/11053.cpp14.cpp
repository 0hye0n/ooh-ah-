#include <bits/stdc++.h>

using namespace std;

int data[1009], dp[1009], n, mx=-1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)cin>>data[i];
	
	for(int i = 0; i < n; i++)
	{
		if(dp[i]==0)dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if(data[i]>data[j])
			{
				if(dp[i]<dp[j]+1)
					dp[i] = dp[j]+1;
			}
		}
	}
	sort(dp, dp+n);
	cout<<dp[n-1];
	return 0;
}