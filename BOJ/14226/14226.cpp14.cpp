#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
//#define push_back pb
//#define emplace_back eb
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

struct status
{
	i32 cur, cnt, clip;
};

i32 s, cnt = 0;
bool flag = false, check[10009][10009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;

	queue <status> bfs;
	bfs.push({1, 0, 0});

	while(!bfs.empty())
	{
		i32 size = bfs.size();
		while(size--)
		{
			i32 tcur = bfs.front().cur, tcnt = bfs.front().cnt, tclip = bfs.front().clip;
			bfs.pop();
			if(tcur == s) flag = true;

			if(tclip != 0 && tcur + tclip <= 10009)
			{
				if(!check[tcur + tclip][tclip])
				{
					check[tcur + tclip][tclip] = true;
					bfs.push({tcur + tclip, tcnt+1, tclip});	
				}
				
			}

			if(tcur > tclip)
			{
				if(!check[tcur][tcur])
				{
					check[tcur][tcur] = true;
					bfs.push({tcur, tcnt+1, tcur});
				}
			}

			if(tcur - 1 > 0)
			{
				if(!check[tcur - 1][tclip])
				{
					check[tcur - 1][tclip] = true;
					bfs.push({tcur-1, tcnt+1, tclip});
				}				
			}
		}
		if(flag)break;
		cnt++;
	}

	cout<<cnt;

	return 0;
}