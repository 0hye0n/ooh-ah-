#include <bits/stdc++.h>
using namespace std;
int data[1009][1009];
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, 1, 0, -1};
int ansx, ansy, status;
int main() 
{
	int n, a;scanf(" %d %d", &n, &a);
	int x=0, y=0;	
	for(int i = n*n; i>0; i--)
	{
		data[x][y] = i;
		if(i==a){ansx=x;ansy=y;}
		int nx = x+dx[status];
		int ny = y+dy[status];
		if(nx<0||ny<0||nx>=n||ny>=n||data[nx][ny])status = (status+1)%4;
			x = x+dx[status];
			y = y+dy[status];
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			printf("%d ", data[i][j]);
		printf("\n");
	}
	printf("%d %d\n", ansx+1, ansy+1);
		
}