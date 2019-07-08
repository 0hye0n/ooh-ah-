#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 a[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a[0]>>a[1]>>a[2];
	while(a[0]||a[1]||a[2])
	{
		if(a[1]-a[0]==a[2]-a[1]&&a[1]-a[0]!=0)
		{
			cout<<"AP "<<a[2]+a[1]-a[0]<<"\n";
		}
		else
		{
			cout<<"GP "<<a[2]*(a[1]/a[0])<<"\n";
		}

		cin>>a[0]>>a[1]>>a[2];
	}
	return 0;
}