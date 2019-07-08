#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int c;lld cnt=0;
bool check[1009][1009];
bool ans[1009][1009];
lld res[1009];
lld temp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 1; i<=1000; i++)
	{
		for(int j = 0; j<=i; j++)
		{
			if(!check[i][j])
			{
				ans[i][j] = true;temp++;
				for(int l = 1; l*i<=1000&&l*j<=1000; l++)check[l*i][l*j] = true;
			}
		}
		for(int j = 0; j<i; j++)
		{
			if(!check[j][i])
			{
				ans[j][i] = true;temp++;
				for(int l = 1; l*j<=1000&&l*i<=1000; l++)check[l*j][l*i] = true;
			}
		}
		res[i] = temp;
	}
	cin>>c;
	while(c--)
	{
		int n;cin>>n;
		cout<<res[n]<<"\n";
	}

	return 0;
}