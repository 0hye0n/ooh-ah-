#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t, s[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 ans=0;
		for(i32 i = 0; i<5; i++)cin>>s[i];
		sort(s, s+5);
		if(s[3]-s[1]>=4)cout<<"KIN\n";
		else cout<<s[1]+s[2]+s[3]<<"\n";
	}
	return 0;
}