#include <bits/stdc++.h>

using namespace std;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int data[10][10], n, m, mx = 0;
bool visit[10][10];
vector <pair<int, int> > virus;

int main()
{

	scanf("%d %d", &n, &m);
	for(int i = 0;i<n;i++)
		for(int j = 0; j<m; j++)
		{
			scanf(" %d", &data[i][j]);
			if(data[i][j]==2)virus.push_back({i, j});
		}
		queue <pair<int, int> > bfs;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			for(int l = i; l<n; l++)
				for(int k = i==l?j+1:0; k<m; k++)
					for(int r = l; r<n; r++)
						for(int u = l==r?k+1:0; u<m; u++)
						{
							if(data[i][j]==1||data[i][j]==2||data[l][k]==1||data[l][k]==2||data[r][u]==1||data[r][u]==2)continue;
							
							int cnt=0;
							for(int z=0; z<virus.size(); z++)
							{
								int x = virus[z].first;
								int y = virus[z].second;
								bfs.push({x, y});
							}
							data[i][j] = 1;
							data[l][k] = 1;
							data[r][u] = 1;
							//bfs
							while(!bfs.empty())
							{
								int size = bfs.size();
							//	printf("%d\n\n", size);
								while(size--)
								{
									int x = bfs.front().first;
									int y = bfs.front().second;
									bfs.pop();
									for(int a = 0; a<4; a++)
									{
										int nx = x+dx[a];
										int ny = y+dy[a];

										if(data[nx][ny]==2||data[nx][ny]==1||nx<0||ny<0||nx>=n||ny>=m||visit[nx][ny])continue;
										visit[nx][ny] = true;
										data[nx][ny] = 2;
										bfs.push({nx, ny});
									}
								}
							}
							while(!bfs.empty())bfs.pop();
						
							for(int a = 0; a<n; a++)
								for(int b = 0; b<m; b++)
									if(data[a][b]==0)cnt++;

							if(mx<cnt)mx = cnt;
								
							for(int a = 0; a<n; a++)
								for(int b = 0; b<m; b++)
									if(visit[a][b])data[a][b]=0;
									
							data[i][j] = 0;
							data[l][k] = 0;
							data[r][u] = 0;
							for(int a = 0; a<10; a++)
								for(int b = 0; b<10; b++)
										visit[a][b] = false;
					}
						printf("%d", mx);
	return 0;
}