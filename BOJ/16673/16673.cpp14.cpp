#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 c, k, p;
i64 sum = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>k>>p;
	for(i32 i = 1; i<=c; i++)sum+=k*i+p*i*i;
	cout<<sum;
	return 0;
}