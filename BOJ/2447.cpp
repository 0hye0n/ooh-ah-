#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n;
char output[7000][7000];

void solve(int sx, int sy, int size)
{
	if(size == 1)
	{
		output[sx][sy] = '*';
		return;
	}
	int s = size / 3;
	solve(sx, sy, s);
	solve(sx + s, sy, s);
	solve(sx + 2 * s, sy, s);
	solve(sx, sy + s, s);
	solve(sx, sy + 2 * s, s);
	solve(sx + 2 * s, sy + s, s);
	solve(sx + s, sy + 2 * s, s);
	solve(sx + 2 * s, sy + 2 * s, s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	memset(output, 0, sizeof(output));
	solve(0, 0, n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout<<(output[i][j] == '*' ? "*" : " ");
		cout<<"\n";
	}
	return 0;
}