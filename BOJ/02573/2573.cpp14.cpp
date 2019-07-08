#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, d[309][309], year = 0, cnt=0;
bool visit[309][309];
vector <pair<int, int> > data;
int sub[10000];
int main()
{

	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
		{
			scanf(" %d", &d[i][j]);
			if(d[i][j]!=0)data.push_back({i, j});
		}
	queue <pair<int, int> > bfs;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
			{
				if(d[i][j]!=0&&!visit[i][j])
				{
					bfs.push({i, j});
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
								if(nx<0||ny<0||nx>=n||ny>=m||d[nx][ny]==0||visit[nx][ny])continue;
								bfs.push({nx, ny});
								visit[nx][ny]=true;
							}
						}
					}
					cnt++;
				}
			}
	int acnt = -1;
	while(acnt!=0)
	{
		acnt=0;
		year++;
		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
				visit[i][j] = false;
		
		for(int i = 0; i<data.size(); i++)
		{
			int temp=0, x=data[i].first, y=data[i].second;
			for(int j = 0; j<4; j++)
			{
				if(d[x+dx[j]][y+dy[j]]==0)temp++;
			}
			sub[i] = temp;
		}
		for(int i = 0; i<data.size(); i++)
		{
			int x=data[i].first, y=data[i].second;
			if(d[x][y]<=sub[i])d[x][y]=0;
			else d[x][y]-=sub[i];	
		}

		for(int i = 0; i<n; i++)
			for(int j = 0; j<m; j++)
			{
				if(d[i][j]!=0&&!visit[i][j])
				{
					bfs.push({i, j});
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
								if(nx<0||ny<0||nx>=n||ny>=m||d[nx][ny]==0||visit[nx][ny])continue;
								bfs.push({nx, ny});
								visit[nx][ny]=true;
							}
						}
					}
					acnt++;
				}
			}
			if(acnt>cnt){printf("%d", year);return 0;}
	}
	printf("0");
	return 0;
}