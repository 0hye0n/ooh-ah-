#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
const int dx[] = {0, 0, 1, 1};
const int dy[] = {0, 1, 0, 1};
int n, r, c, ans;
lld cnt=0;
inline lld POW(lld n)
{
	lld value = 1;
	return value<<=n;
}
void solve(int n, int x, int y)
{
	if(n==2)
	{
		if(!(x<=r&&r<=x+1&&y<=c&&c<=y+1)){cnt+=4;return;}
		for(int i = 0; i<4; i++)
		{
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx==r&&ny==c)ans=cnt;
			if(i<3)cnt++;
		}
		cnt++;
		return;
	}
	solve(n/2, x, y);
	solve(n/2, x, y+n/2);
	solve(n/2, x+n/2, y);
	solve(n/2, x+n/2, y+n/2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>r>>c;
	lld size = POW(n), cnt=0;
	solve(size, 0, 0);
	cout<<ans;
	return 0;
}

