#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 a, b, c, sum;bool check[2] = {false, false};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c;
	sum+=a+b;
	if(sum<2*c)cout<<a+b;
	else cout<<a+b-2*c;
	return 0;
}