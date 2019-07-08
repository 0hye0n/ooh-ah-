#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define push_back pb
#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef short i8;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, m, greedy[3][59], mn = 2e9, res=0, cnt[3] = {0, 0, 0};
char data[59][59], color[3] = {'W', 'B', 'R'};

void solve(i32 pos, i32 pre)
{
	if(pos==n)
	{
		if(!cnt[0]||!cnt[1]||!cnt[2])return;
		if(res<mn)mn = res;
		return;
	}
	for(i32 i = 0; i<3; i++)
	{
		if(pre>i) continue;
		cnt[i]++;
		res += m-greedy[i][pos];
		solve(pos+1, i);
		cnt[i]--;
		res -= m-greedy[i][pos];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	memset(greedy, 0, sizeof(greedy));
	for(i32 i = 0; i < n; i++)
		for(i32 j = 0; j < m; j++)
			cin>>data[i][j];
	for(i32 i = 0; i < 3; i++)
		for(i32 j = 0; j < n; j++)
			for(i32 k = 0; k < m; k++)
				if(data[j][k]==color[i])greedy[i][j]++;
	solve(0, 0);
	cout<<mn;
	return 0;
}