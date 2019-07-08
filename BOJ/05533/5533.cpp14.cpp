#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, cnt[3][109];
vector<vector<int>> player;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	player.resize(n+9);
	for(int i = 0; i<n; i++){
		for(int j = 0; j<3; j++)
		{
			int temp;cin>>temp;
			player[i].push_back(temp);
			cnt[j][temp]++;
		}
	}
	for(int i = 0; i<n; i++){
		int res=0;
		for(int j = 0; j<3; j++)
		{
			if(cnt[j][player[i][j]]>1)continue;
			res+=player[i][j];
		}
		cout<<res<<"\n";
	}
	return 0;
}