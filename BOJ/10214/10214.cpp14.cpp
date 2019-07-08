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
		i32 yon=0, kor=0;
		for(i32 i = 0; i<9; i++)
		{
			i32 y, k;cin>>y>>k;
			yon+=y;kor+=k;
		}
		if(yon>kor)cout<<"Yonsei\n";
		else if(yon<kor)cout<<"Korea\n";
		else cout<<"Draw\n";
	}
	return 0;
}