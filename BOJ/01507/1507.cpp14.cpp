#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n, d[29][29];lld sum = 0;bool flag = false, check[29][29];
void floyd(){
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			for(int k = 0; k<n; k++){
				if(j==k||i==j||i==k)continue;
				if(d[j][k]==d[j][i]+d[i][k]){check[j][k]=true;}
				else if(d[j][k]>d[j][i]+d[i][k]){flag = true;}
			}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>d[i][j];
	floyd();
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			if(!check[i][j])sum+=d[i][j];
	if(flag)cout<<"-1";
	else cout<<sum/2;
	return 0;
}