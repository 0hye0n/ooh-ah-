#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, cnt = 0;
bool check[19][19];
bool curcheck[19];

void solve(int pos)
{
	if(pos == 0){cnt++;return;}


	for(int i = 0; i < n; i++)
		for(int j = 0; j < )
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cnt = 0;
		memset(check, false, sizeof(check));
		memset(curcheck, false, sizeof(curcheck));

		int n, m;cin>>n>>m;
		
		for(int i = 0; i < m; i++)
		{
			int x, y;cin>>x>>y;
			check[x][y] = true;
			check[y][x] = true;
		}

		solve(n / 2);
	}

	return 0;
}