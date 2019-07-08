#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int dice[6] = {0, 0, 0, 0, 0, 0};
int command[1009];
int n, m, x, y, k, data[29][29];
bool flag = false;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void move(int direction)
{
	int nx = x+dx[direction-1];
	int ny = y+dy[direction-1];
	if(nx<0||ny<0||nx>=n||ny>=m)
		{
			flag = true;
			return;
		}
	x += dx[direction-1];
	y += dy[direction-1];
	if(direction==1)
	{
		swap(&dice[1], &dice[5]);
		swap(&dice[1], &dice[4]);
		swap(&dice[4], &dice[3]);
	}
	else if(direction==2)
	{
		swap(&dice[3], &dice[4]);
		swap(&dice[1], &dice[4]);
		swap(&dice[1], &dice[5]);
		
	}
	else if(direction==3)
	{
		swap(&dice[0], &dice[1]);
		swap(&dice[1], &dice[2]);
		swap(&dice[2], &dice[3]);
	}
	else if(direction==4)
	{
		swap(&dice[2], &dice[3]);
		swap(&dice[1], &dice[2]);
		swap(&dice[0], &dice[1]);
	}
}
int main()
{
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m; j++)
			scanf(" %d", &data[i][j]);

	for(int i = 0; i<k; i++)scanf(" %d", &command[i]);

	for(int i = 0; i<k; i++)
	{
		move(command[i]);
		if(!flag)
		{
			if(data[x][y]==0)data[x][y]=dice[3];
			else
			{
				dice[3] = data[x][y];
				data[x][y] = 0;
			} 
			printf("%d\n", dice[1]);	
		}
		flag=false;
	}


	return 0;
}