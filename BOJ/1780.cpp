#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, arr[2200][2200], ans[3];

void solve(int sx, int sy, int size)
{
	int cmp = arr[sx][sy];

	bool flag = false;

	for(int i = sx; i < sx + size; i++){
		for(int j = sy; j < sy + size; j++)
			if(arr[i][j] != cmp)
			{
				flag = true;
				break;
			}
		if(flag)break;
	}

	if(flag)
	{
		int s = size / 3;
		solve(sx, sy, s);
		solve(sx, sy + s, s);
		solve(sx, sy + 2 * s, s);
		solve(sx + s, sy, s);
		solve(sx + s, sy + s, s);
		solve(sx + s, sy + 2 * s, s);
		solve(sx + 2 * s, sy, s);
		solve(sx + 2 * s, sy + s, s);
		solve(sx + 2 * s, sy + 2 * s, s);
	}

	else
	{
		switch(cmp)
		{
			case 1:
				ans[2]++;
				break;

			case 0:
				ans[1]++;
				break;

			case -1:
				ans[0]++;
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>arr[i][j];
	solve(0, 0, n);
	for(int i = 0; i < 3; i++)cout<<ans[i]<<"\n";
	return 0;
}