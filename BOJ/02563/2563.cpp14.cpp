#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, res;
bool check[109][109];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n--)
	{
		int x, y;cin>>x>>y;
		for(int i = x; i<x+10; i++)
			for(int j = y; j<y+10; j++)
				check[i][j]=true;
	}

	for(int i = 0; i<101; i++)
		for(int j = 0; j<101; j++)
			if(check[i][j])res++;
	cout<<res;

	return 0;
}