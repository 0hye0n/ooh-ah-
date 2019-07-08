#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

//#define push_back pb
//#define emplace_back eb
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef short i8;
typedef int i32;
typedef long long i64;
typedef unsigned short ui8;
typedef unsigned int ui32;
typedef unsigned long long ui64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;

const i32 MOD = 1e9;
i32 n, k;
i64 dp[209][209];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(i32 i = 0; i < 201; i++)dp[0][i] = 1;

	for(i32 i = 1; i <= n; i++)
	{
		for(i32 j = 1; j <= k; j++)
		{
			for(i32 t = i; t >= 0; t--)
			{
				dp[i][j] += dp[i-t][j-1];
				dp[i][j] %= MOD;
			}
		}
	}
	cout<<dp[n][k];
	return 0;
}