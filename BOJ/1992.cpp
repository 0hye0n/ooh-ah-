#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, arr[70][70];

void solve(int sx, int sy, int size)
{
	//cout<<"\n"<<sx<<" "<<sy<<" "<<size<<"\n";
	int flag = false, cmp = arr[sx][sy];
	for(int i = sx; i < sx + size; i++){
		for(int j = sy; j < sy + size; j++)
			if(cmp != arr[i][j])
			{
				flag = true;
				break;
			}
		if(flag)break;
	}

	if(flag)
	{
		int s = size / 2;
		cout<<"(";
		solve(sx, sy, s);
		solve(sx, sy + s, s);
		solve(sx + s, sy, s);
		solve(sx + s, sy + s, s);
		cout<<")";
	}

	else
	{
		cout<<cmp;
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin>>n;		
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf(" %1d", &arr[i][j]);

	solve(0, 0, n);
	return 0;
}