#include <bits/stdc++.h>

using namespace std;
int d[109][109], n, twin, cnt=0;

void floyd()
{
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			for(int k = 1; k<=n; k++)
				if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
}
int main() 
{
	scanf("%d %d", &n, &twin);
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			if(i!=j)d[i][j]=987654321;
			
	
	for(int i = 0; i<twin; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(d[x][y]==987654321){d[x][y]=1;d[y][x]=1;}
	}
	floyd();
	for(int i = 1; i<=n; i++)if(d[1][i]!=987654321)cnt++;
	printf("%d\n", cnt-1);
		
	return 0;
	}