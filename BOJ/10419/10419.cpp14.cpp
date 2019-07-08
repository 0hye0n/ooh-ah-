#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 d, ans=0;cin>>d;
		for(i32 i = 0;;i++)
		{
			if(i*i+i<=d)ans=i;
			else break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}