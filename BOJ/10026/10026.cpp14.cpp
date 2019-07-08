#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, cnt=0, ncnt=0;
char saram[109][109];
char nosaram[109][109];
bool visit[109][109];
bool nvisit[109][109];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
		{
			char temp;scanf(" %c", &temp);
			saram[i][j] = temp;
			if(temp=='G')nosaram[i][j] = 'R';
			else nosaram[i][j] = temp;	
		}

	queue <pair<int, int> > bfs;

	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
		{
			if(!visit[i][j])
			{
				char cur = saram[i][j];
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
							if(nx<0||ny<0||nx>=n||ny>=n||saram[nx][ny]!=cur||visit[nx][ny])continue;
							visit[nx][ny] = true;
							bfs.push({nx, ny});
						}
					}
				}
				cnt++;
			}
		}
		while(!bfs.empty())bfs.pop();
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
			{
				if(!nvisit[i][j])
				{
					char cur = nosaram[i][j];
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
								if(nx<0||ny<0||nx>=n||ny>=n||nosaram[nx][ny]!=cur||nvisit[nx][ny])continue;
								nvisit[nx][ny] = true;
								bfs.push({nx, ny});
							}
						}
					}
					ncnt++;
				}
			}
		printf("%d %d\n", cnt, ncnt);
	return 0;
}