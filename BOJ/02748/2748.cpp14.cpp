#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 pabo[99], n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	pabo[0] = 0;
	pabo[1] = 1;
	for(i32 i = 2; i<=90; i++)pabo[i]=pabo[i-1]+pabo[i-2];
	cin>>n;cout<<pabo[n];
	return 0;
}