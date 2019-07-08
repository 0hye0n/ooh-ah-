#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
int d[59][59];
int hoobo[59];
int mn = 0x7FFFFFFF;

void floyd()
{
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			for(int k = 1; k<=n; k++)
				if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			d[i][j] = 0x7FFF;
	int x, y;cin>>x>>y;
	while(x!=-1&&y!=-1)
	{
		d[x][y]=1;
		d[y][x]=1;
		cin>>x>>y;
	}
	floyd();
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			if(i==j)continue;
			hoobo[i] = max(hoobo[i], d[i][j]);
		}
		mn = min(mn, hoobo[i]);
	}
	int cnt = 0;
	for(int i = 1; i<=n; i++)if(hoobo[i]==mn)cnt++;
	cout<<mn<<" "<<cnt<<"\n";
	for(int i = 1; i<=n; i++)if(hoobo[i]==mn)cout<<i<<" ";
	return 0;
		
}