#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool check[509][509];
int mp[509][509], mx = 0, n, m, rec = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin>>mp[i][j];

	queue <pair<int, int>> bfs;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(mp[i][j] == 0 || check[i][j])continue;
			rec++;
			check[i][j] = true;
			bfs.push(make_pair(i, j));
			int cnt = 0;

			while(!bfs.empty())
			{
				int size = bfs.size();
				while(size--)
				{
					cnt++;
					int x = bfs.front().first;
					int y = bfs.front().second;
					bfs.pop();

					for(int i = 0; i < 4; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];

						if(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || mp[nx][ny] == 0)continue;

						bfs.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}

			mx = max(mx, cnt);
		}
	cout<<rec<<"\n"<<mx;
	return 0;
}