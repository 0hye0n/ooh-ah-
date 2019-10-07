#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m[29][29];
int mem[29][29][29][29][2];

int solve(int sx, int sy, int x, int y, bool dir)
{

	if(mem[sx][sy][x][y][dir == true ? 1 : 0] != -1) return mem[sx][sy][x][y][dir];

	int ret = 0, cnt = 0;
	bool perfect = true;

	vector <pair<int, int>> v;

	for(int i = sx; i < sx + x; i++)
		for(int j = sy; j < sy + y; j++)
		{
			if(m[i][j] == 1)
			{
				perfect = false;
				v.push_back(make_pair(i, j));
			}

			else if(m[i][j] == 2)cnt++;
		}

	

	if(perfect && cnt == 1){
		return 1;} 
	else if(cnt == 0) return 0;
	else if(perfect && (cnt == 0 || cnt >= 2)) return 0;

	for(auto p : v)
	{
		bool flag = false;

		if(dir)//ㅡ
		{
			for(int j = sy; j < sy + y; j++)
			{
				if(m[p.first][j] == 2)
				{
					flag = true;
					break;
				}
			}

			if(flag) continue;
			
			ret += solve(sx, sy, p.first - sx, y, !dir) * solve(p.first + 1, sy, sx + x - p.first - 1, y, !dir);
		}

		else//ㅣ
		{
			for(int j = sx; j < sx + x; j++)
			{
				if(m[j][p.second] == 2)
				{
					flag = true;
					break;
				}
			}

			if(flag) continue;
			ret += solve(sx, sy, x, p.second - sy, !dir) * solve(sx, p.second + 1, x, sy + y - p.second - 1, !dir);
		}
	}

	mem[sx][sy][x][y][dir == true ? 1 : 0] = ret;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(mem, -1, sizeof(mem));
	bool check = false;
	int cnt = 0;
	cin>>n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			cin>>m[i][j];

			if(m[i][j] == 2)cnt++;
			else if(m[i][j] == 1) check = true;
		}
	
	if(!check && cnt == 1){
		cout<<"1";
		return 0;
	}

	int ans = solve(0, 0, n, n, true) + solve(0, 0, n, n, false);

	if(ans == 0)cout<<"-1";
	else cout<<ans;

	return 0;
}