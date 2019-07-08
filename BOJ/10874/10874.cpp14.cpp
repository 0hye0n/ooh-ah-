#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 n, ans[11];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(i32 i = 1; i<=10; i++)ans[i] = (i-1)%5+1;
	cin>>n;
	for(i32 i = 1; i<=n; i++)
	{
		i32 cnt=0;
		for(i32 j = 1; j<=10; j++){i32 temp;cin>>temp;if(ans[j]==temp)cnt++;}
		if(cnt==10)cout<<i<<"\n";
	}
	return 0;
}