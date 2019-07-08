#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 mn[3], mx[3], n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(i32 i = 0; i<n; i++)
	{
		i32 t1, t2, t3;cin>>t1>>t2>>t3;
		i32 a = mx[0], b = mx[1], c = mx[2];
		mx[0] = max(a, b)+t1;
		mx[1] = max({a, b, c})+t2;
		mx[2] = max(b, c)+t3;
		a = mn[0];
		b = mn[1];
		c = mn[2];
		mn[0] = min(a, b)+t1;
		mn[1] = min({a, b, c})+t2;
		mn[2] = min(b, c)+t3;

	}
	cout<<max({mx[0], mx[1], mx[2]})<<" "<<min({mn[0], mn[1], mn[2]});
	return 0;
}