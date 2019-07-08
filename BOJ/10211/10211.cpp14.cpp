#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t, data[1009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 n, sum=0, res = -2e9;cin>>n;
		for(i32 i = 1; i<=n; i++)
		{
			i32 temp;cin>>temp;
			sum+=temp;
			data[i]=sum;	
		}
		for(i32 i = n; i>0; i--)
			for(i32 j = i-1; j>=0; j--)
			{
				res=max(res, data[i]-data[j]);
			}
		cout<<res<<"\n";
	}
	return 0;
}