#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

i64 ccw(pii64 a, pii64 b, pii64 c)
{
	i64 res = a.first*b.second + b.first*c.second + c.first*a.second;
	res -= a.second*b.first + b.second*c.first + c.second*a.first;
	return res;
}
i32 n;i64 ans=0;
pii64 data[10009], temp;  
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(1);
	cout<<fixed;
	temp.first = 1;temp.second = 1;
	cin>>n;
	for(int i = 0; i<n; i++)cin>>data[i].first>>data[i].second;
	for(int i = 0; i<n-1; i++)ans += ccw(data[i], data[i+1], temp);
	ans += ccw(data[n-1], data[0], temp);
	cout<<fabs((double)ans/2.0);

	return 0;
}