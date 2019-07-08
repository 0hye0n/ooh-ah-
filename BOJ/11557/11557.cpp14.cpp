#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t;
vector <pair<i32, string>> data;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 n;cin>>n;
		for(i32 i = 0; i<n; i++)
		{
			string t1;i32 t2;cin>>t1>>t2;
			data.push_back(make_pair(t2, t1));
		}
		sort(data.begin(), data.end());
		cout<<data.back().second<<"\n";
		data.clear();
	}
	return 0;
}