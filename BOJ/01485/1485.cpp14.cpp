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
inline i64 distance(pii64 a, pii64 b)
{
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
inline i32 ccw(pii64 a, pii64 b, pii64 c)
{
	i64 res = a.first*b.second + b.first*c.second+c.first*a.second;
	res -= a.second*b.first + b.second*c.first+c.second*a.first;
	if(res>0) return 1;
	else if(res==0) return 0;
	else return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		bool flag = false;
		vector <pii64> dot(4);
		for(i32 i = 0; i<4; i++)cin>>dot[i].first>>dot[i].second;
		sort(dot.begin(), dot.end());
		i64 check[4];
		check[0] = ccw(dot[0], dot[1], dot[3]); 
		check[1] = ccw(dot[1], dot[3], dot[2]);
		check[2] = ccw(dot[3], dot[2], dot[0]);
		check[3] = ccw(dot[2], dot[0], dot[1]);
		for(int i = 1; i<4; i++)if(check[i]!=check[i-1])flag=true;
		check[0] = distance(dot[0], dot[1]); 
		check[1] = distance(dot[1], dot[3]);
		check[2] = distance(dot[3], dot[2]);
		check[3] = distance(dot[2], dot[0]);
		for(int i = 1; i<4; i++)if(check[i]!=check[i-1])flag=true;
		if(check[0]+check[1]!=distance(dot[0], dot[3]))flag=true;
		cout<<(flag?"0\n":"1\n");
	}
	return 0;
}