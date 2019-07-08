#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int d[109][109], n;
bool visit[109][109];
int mx = 0;
int main() 
{
	
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			scanf(" %d", &d[i][j]);
	queue <pair<int, int> > bfs;
	for(int i = 0; i<=100; i++)
	{
		int cnt=0;
		for(int j = 0; j<n; j++)
			for(int l = 0; l<n; l++)
		{
			if(d[j][l]>i&&(!visit[j][l]))
			{
				bfs.push({j, l});
				while(!bfs.empty())
				{	
					int size = bfs.size();
					while(size--)
					{
						int x = bfs.front().first;
						int y = bfs.front().second;
						bfs.pop();
						for(int k = 0; k<4; k++)
						{
							int nx =x+dx[k];
							int ny =y+dy[k];
							if(nx<0||ny<0||nx>=n||ny>=n||visit[nx][ny]||d[nx][ny]<=i)continue;
							bfs.push({nx, ny});	
							visit[nx][ny] = true;
						}
					}
				}		
				cnt++;				
			}
			
			
				
		}
		for(int j = 0; j<n; j++)
			for(int k = 0; k<n; k++)
				visit[j][k]=false;
		
		if(cnt>mx)mx = cnt;
	}
	
	printf("%d", mx);
	
	
	return 0;
}