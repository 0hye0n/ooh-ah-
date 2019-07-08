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

struct Cont{
	i32 country, gold, silver, bronze;
};

bool cmp(const Cont &a, const Cont &b)
{
	if(a.gold != b.gold) return a.gold > b.gold;
	if(a.silver != b.silver) return a.silver > b.silver;
	return a.bronze > b.bronze;
}
i32 n, k;

vector<Cont> data;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(i32 i = 0; i < n; i++)
	{
		i32 a, b, c, d;cin>>a>>b>>c>>d;
		data.push_back({a, b, c, d});
	}

	sort(data.begin(), data.end(), cmp);
	i32 index, ans;
	for(i32 i = 0; i < n; i++)
	{
		if(data[i].country==k)
		{
			index = i;
			break;
		}
	}
	ans = index;
	for(i32 i = index-1; i >= 0; i--)
	{
		if(data[index].gold==data[i].gold && data[index].silver==data[i].silver && data[index].bronze==data[i].bronze)ans--;
	}
	cout<<ans+1;
	return 0;
}