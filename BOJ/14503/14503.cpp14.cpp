#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef short i8;
typedef int i32;
typedef long long i64;
typedef unsigned short ui8;
typedef unsigned int ui32;
typedef unsigned long long ui64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

struct status{
	i32 r, c, d;
};
//차례대로 북! 동! 남! 서! 쓰
//const i32 dx[] = {-1, 0, 1, 0};
//const i32 dy[] = {0, 1, 0, -1};
const i32 dd[] = {3, 2, 1, 0};
//서 남 동 북
const i32 dx[] = {0, 1, 0, -1};
const i32 dy[] = {-1, 0, 1, 0};

i32 n, m, r, c, d, maaap[59][59], ans=0, cnt=0;
bool check[59][59];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>r>>c>>d;

	for(i32 i = 0; i < n; i++)
		for(i32 j = 0; j < m; j++)
			cin>>maaap[i][j];

	queue <status> bfs;

	bfs.push({r, c, dd[d]});
	cnt++;
	check[r][c] = true;

	while(!bfs.empty())
	{
		i32 size = bfs.size();

		while(size--)
		{
			bool flag = false;
			i32 x = bfs.front().r, y = bfs.front().c, z = bfs.front().d;
			bfs.pop();
			for(i32 i = 1; i <= 4; i++)
			{ 
				i32 nr = x + dx[(z+i)%4];
				i32 nc = y + dy[(z+i)%4];
				if(maaap[nr][nc] == 1 || nr >= n || nc >= m || check[nr][nc] || nr < 0 || nc < 0) continue;
				flag=true;
				check[nr][nc] = true;
				bfs.push({nr, nc, (z+i)%4});
				cnt++;
				break;
			}
			
			if(!flag)
			{
				i32 nr = x+dx[(z+2)%4];
				i32 nc = y+dy[(z+2)%4];
				if(maaap[nr][nc] == 1 || nr >= n || nc >= m || nr < 0 || nc < 0) break;
				bfs.push({nr, nc, z});
			}
			
		}
	}
	
	cout<<cnt<<"\n";
	return 0;
}