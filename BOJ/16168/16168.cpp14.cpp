#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int v, e, cnt[3009], check=0;
bool access[3009];
vector <vector<int>> vt;
void solve(int pos)
{
	access[pos]=true;
	for(auto p : vt[pos])
	{
		if(access[p])continue;
		access[p]=true;
		solve(p);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>v>>e;
	vt.resize(v+9);
	for(int i = 0; i<e; i++)
	{
		int x, y;cin>>x>>y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}
	bool flag = false;
	solve(1);
	for(int i = 1; i<=v; i++)if(!access[i]){flag=true;break;}
	for(int i = 1; i<=v; i++)cnt[i] = vt[i].size();
	for(int i = 1; i<=v; i++)if(cnt[i]%2==1)check++;
	if(!flag&&(check==0||check==2))cout<<"YES";
	else cout<<"NO";
	return 0;
}