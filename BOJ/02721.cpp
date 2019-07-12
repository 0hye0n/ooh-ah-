#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int t, sum[309];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(int i = 1; i <= 300 ; i++)
	{
		sum[i] = sum[i-1] + i * (((i + 1) * (i + 2)) / 2);
	}
	while(t--)
	{
		int n;cin>>n;
		cout<<sum[n]<<"\n";
	}
	return 0;
}