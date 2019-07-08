#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
f64 h, p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(2);
	cout<<fixed;
	while(cin>>h>>p)cout<<h/p<<"\n";	
	return 0;
}