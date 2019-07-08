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

i32 n, m, cnt[32009];

vector <vector<i32>> v;
queue <i32> data;
stack <i32> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n+9);
	for(i32 i = 0; i < m; i++)
	{
		i32 x, y;cin>>x>>y;
		v[y].push_back(x);
		cnt[x]++;
	}

	for(i32 i = 1; i<=n; i++)
	{
		if(cnt[i]==0)data.push(i);
	}

	while(!data.empty())
	{
		i32 temp = data.front();
		data.pop();
		ans.push(temp);

		i32 size = v[temp].size();

		for(i32 i = 0; i < size; i++)
		{
			if(cnt[v[temp][i]]==0)continue;
			cnt[v[temp][i]]--;
			if(cnt[v[temp][i]]==0)data.push(v[temp][i]);
	
		}
	}
	while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}

	return 0;
}