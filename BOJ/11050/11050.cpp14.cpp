#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, k, ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	i32 temp=1;
	for(i32 i = 1; i<=n; i++)ans*=i;
	for(i32 i = 1; i<=k; i++)temp*=i;
	for(i32 i = 1; i<=n-k; i++)temp*=i;
	cout<<ans/temp;

	return 0;
}