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

bool check[1009];
i32 t;
vector<vector<i32>> vt;

i32 solve(i32 s)
{
	i32 cnt = 0;
	queue<int> q;
	q.push(s);
	check[s] = true;
	for(auto p : vt[s])
	{
		q.push(p);
	}

	while(!q.empty())
	{
		i32 cur = q.front();
		q.pop();
		if(check[cur] == true)continue;
		check[cur] = true;
		cnt++;
		for(auto p : vt[cur])
		{
			if(check[p] == true)continue;
			q.push(p);
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		memset(check, false, sizeof(check));
		vt.clear();

		i32 n, m;cin>>n>>m;
		vt.resize(n+1);
		for(i32 i = 0; i < m; i++)
		{
			i32 x, y;cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		cout<<solve(1)<<"\n";
	}

	return 0;
}
