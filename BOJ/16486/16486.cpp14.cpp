#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define PI 3.141592
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
f64 d1, d2, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(6);
	cout<<fixed;
	cin>>d1>>d2;
	ans = d1*2+2*d2*PI;
	cout<<ans;
	return 0;
}