#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int m, n, k, cnt=0;
int data[109][109], size[109];
bool visit[109][109];
int main()
{
	scanf("%d %d %d", &m, &n, &k);
	for(int i = 0; i<k; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int a = y1; a<y2; a++)
			for(int b = x1; b<x2; b++)
				data[a][b] = 1;
	}
	queue <pair<int, int> > bfs;
	for(int i = 0; i<m; i++)
		for(int j = 0; j<n; j++)
		{
			if(!visit[i][j]&&data[i][j]==0)
			{
				int sizecnt=1;
				bfs.push({i, j});
				visit[i][j] = true;
				while(!bfs.empty())
				{
					int size = bfs.size();
					while(size--)
					{
						int x = bfs.front().first;
						int y = bfs.front().second;
						bfs.pop();
						for(int i = 0; i<4; i++)
						{
							int nx = x+dx[i];
							int ny = y+dy[i];
							if(nx<0||ny<0||nx>=m||ny>=n||data[nx][ny]==1||visit[nx][ny])continue;
							visit[nx][ny] = true;
							bfs.push({nx, ny});
							sizecnt++;
						}							
					}
				}
				size[cnt] = sizecnt;
				cnt++;
			}
		}
		sort(size, size+cnt);
		printf("%d\n", cnt);
		for(int i = 0; i<cnt; i++)printf("%d ", size[i]);
	return 0;
}