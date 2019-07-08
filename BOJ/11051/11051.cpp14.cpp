#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, k, dp[1009][1009];
i64 solve(i32 n1, i32 k1)
{
	if(n1==k1||k1==0)return 1;
	if(dp[n1][k1]>0)return dp[n1][k1];
	return dp[n1][k1] = (solve(n1-1, k1-1) + solve(n1-1, k1))%MOD;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	cout<<solve(n, k);
	return 0;
}