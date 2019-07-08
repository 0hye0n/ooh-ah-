#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;lld cnt=0;
bool row[19], col[19], d1[39], d2[39];
void solve(int pos)
{
	if(pos==n){cnt++;return;}
	for(int i = 0; i<n; i++)
	{
		if(col[i]||d1[i-pos+n]||d2[pos+i])continue;
		d1[i-pos+n] = true;
		d2[pos+i] = true;
		row[pos] = true;
		col[i] = true;
		solve(pos+1);
		d1[i-pos+n] = false;
		d2[pos+i] = false;
		row[pos] = false;
		col[i] = false;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	solve(0);
	cout<<cnt;
	return 0;
}