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
char data[109];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	i32 i = 0;
	while(t--)
	{
		i++;
		i32 l, cnt=0;cin>>l;
		for(i32 i = 0; i<l; i++)cin>>data[i];
		for(i32 i = 0; i<l; i++)
		{
			char temp;cin>>temp;
			if(data[i]!=temp)cnt++;
		}
		cout<<"Case "<<i<<": "<<cnt<<"\n";
	}
	return 0;
}