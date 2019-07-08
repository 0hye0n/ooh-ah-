#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 t, n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		i32 cnt=0;
		cin>>n>>m;
		for(i32 i = 1; i<n; i++)
			for(i32 j = i+1; j<n; j++)
			{
				f64 t1 = (double)(i*i+j*j+m)/(double)(i*j);
				i32 t2 = (i32)t1;
				if(t1==(double)t2)cnt++;
			}
		cout<<cnt<<"\n";
	}
	return 0;
}