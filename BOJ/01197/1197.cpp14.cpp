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

bool check[10009];
i64 mn = 999999999999;
i32 n, m;
vector<vector<pair<int, int>>> v;

void solve(i32 s)
{
	i64 sum = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	check[s] = true;

	for(auto p : v[s])
	{
		pq.push(make_pair(p.second, p.first));
	}

	while(!pq.empty())
	{
		i32 cost = pq.top().first;
		i32 cur = pq.top().second;
		pq.pop();
		if(check[cur] == true)continue;
		check[cur]=true;
		sum+=cost;
		for(auto p : v[cur])
		{
			if(check[p.first])continue;
			pq.push(make_pair(p.second, p.first));
		}
	}
	memset(check, false, sizeof(check));
	mn = min(mn, sum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n+9);
	for(i32 i = 0; i < m; i++)
	{
		i32 x, y, z;cin>>x>>y>>z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}

	solve(1);
	cout<<mn;
	return 0;
}
