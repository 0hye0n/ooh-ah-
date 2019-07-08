#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, m, d1[1009], d2[1009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(i32 i = 0; i<n; i++)cin>>d1[i];
	for(i32 i = 0; i<m; i++)cin>>d2[i];
	sort(d1, d1+n);
	sort(d2, d2+m);
	cout<<d1[n-1]+d2[m-1];
	return 0;
}