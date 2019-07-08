#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

lld v, e;
lld d[409][409];
lld mn = 2e15;
void floyd(){
	for(int i = 1; i<=v; i++)
		for(int j = 1; j<=v; j++)
			for(int k = 1; k<=v; k++)
				if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>v>>e;
	for(int i = 1; i<=v; i++)
		for(int j = 1; j<=v; j++)
			d[i][j] = 2e15;
	for(int i = 0; i<e; i++){
		lld x, y, z;cin>>x>>y>>z;
		d[x][y] = z;
	}
	floyd();bool flag = false;
	for(int i = 1; i<=v; i++){
		for(int j = 1; j<=v; j++){
			if(i==j)continue;
			if(d[i][j]!=2e15&&d[j][i]!=2e15)
			{
				mn = min(mn, d[i][j]+d[j][i]);
				flag = true;
			}
		}
	}
	if(flag)
	cout<<mn;
	else
	cout<<"-1";
	return 0;
}