#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int t, d[59][59];bool visit[59][59];
int main() 
{
	scanf("%d", &t);
	
	while(t--)
	{
		int  m, n, k, cnt=0;
		scanf(" %d %d %d", &m, &n, &k);
		for(int i = 0; i<k; i++)
		{
			int x, y;scanf("%d %d", &x, &y);
			d[y][x] = 1;
		}
		queue <pair<int, int> > bfs;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
			{
				if(!visit[i][j]&&d[i][j]==1)
				{
					cnt++;
					bfs.push({i, j});
					visit[i][j]==true;
					while(!bfs.empty())
					{
						int size = bfs.size();
						
						while(size--)
						{
							int x, y;
							x=bfs.front().first;
							y=bfs.front().second;
							bfs.pop();
							for(int i = 0; i<4; i++)
							{
								int nx, ny;
								nx = x+dx[i];
								ny = y+dy[i];
								if(nx<0||ny<0||nx>=n||ny>=m||visit[nx][ny]||d[nx][ny]==0)continue;
								bfs.push({nx, ny});
								visit[nx][ny] = true;
							}
						}
					}
				}
			}

		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
				{
					visit[i][j]=false;
					d[i][j]=0;
				}
			
		printf("%d\n", cnt);
		
	}
	
	return 0;
}