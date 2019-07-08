#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define push_back pb
#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

const i32 dx[] = {1, 0, -1, 0};
const i32 dy[] = {0, 1, 0, -1};
i32 r, c;
i32 vans = 0, oans = 0;

char data[259][259];
bool check[259][259];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>r>>c;
	for(i32 i = 0; i < r; i++)
		for(i32 j = 0; j < c; j++)
			cin>>data[i][j];


	queue <pii32> bfs;

	for(i32 i = 0; i < r; i++)
		for(i32 j = 0; j < c; j++)
		{
			if(check[i][j]||data[i][j]=='#')continue;
			i32 to=0, tv=0;

			bfs.push(make_pair(i, j));

			check[i][j]=true;
			if(data[i][j]=='v') tv++;
			else if(data[i][j]=='o') to++;
			
			while(!bfs.empty())
			{

				i32 size = bfs.size();
				while(size--)
				{
					i32 x = bfs.front().first;
					i32 y = bfs.front().second;
					bfs.pop();

					for(i32 k = 0; k < 4; k++)
					{
						i32 nx = x+dx[k];
						i32 ny = y+dy[k];
						if(nx>=r||ny>=c||nx<0||ny<0||data[nx][ny]=='#'||check[nx][ny])continue;
						check[nx][ny]=true;
						if(data[nx][ny]=='v') tv++;
						else if(data[nx][ny]=='o') to++;
						bfs.push(make_pair(nx, ny));
					}
				}
			}

			if(to>tv)oans += to;
			else vans += tv;
		}

		cout<<oans<<" "<<vans;
	return 0;
}