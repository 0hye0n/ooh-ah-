#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, cnt=0, member[700];
char a[30][30];
bool visit[30][30];

int dfs(int x, int y)
{
	int res = 1;
	visit[x][y] = true;
	int nx, ny;
	for(int i = 0; i<4; i++)
	{
		nx = x+dx[i];
		ny = y+dy[i];
		if(nx<0||ny<0||nx>=n||ny>=n||visit[nx][ny]||a[nx][ny]=='0')continue;
		res += dfs(nx, ny);
	}
	return res;
} 
int main() {
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %s", a[i]);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			if((!visit[i][j])&&(a[i][j]=='1'))member[cnt++] = dfs(i, j);
	sort(member, member+cnt);
	printf("%d\n", cnt);
	for(int i = 0; i<cnt; i++)printf("%d\n", member[i]);	
			
	return 0; 
}