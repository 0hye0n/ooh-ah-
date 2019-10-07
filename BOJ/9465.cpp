#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, n, sticker[2][100009], mem[2][100009];

int solve(bool direction, int pos)
{
	if(pos >= n) return 0;

	if(pos == n - 1)
	{
		mem[direction][pos] = sticker[direction][pos];
		return sticker[direction][pos];
	}

	
	if(mem[direction][pos] != -1)
	{
		return mem[direction][pos];
	}

	int ret = sticker[direction][pos];
	ret += max<int>(solve(!direction, pos + 1), solve(!direction, pos + 2));

	mem[direction][pos] = ret;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(mem, -1, sizeof(mem));
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < n; j++)
				cin>>sticker[i][j];

		cout<<max<int>(solve(false, 0), solve(true, 0))<<"\n";
	}
	return 0;
}