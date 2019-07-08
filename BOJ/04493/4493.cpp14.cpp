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
		i32 n, p1=0, p2=0;cin>>n;
		for(i32 i = 0; i<n; i++)
		{
			char t1, t2;cin>>t1>>t2;
			if(t1=='R')
			{
				if(t2=='R'){p1++;p2++;}
				else if(t2=='S')p1++;
				else p2++;
			}
			else if(t1=='S')
			{
				if(t2=='R')p2++;
				else if(t2=='S'){p1++;p2++;}
				else p1++;
			}
			else if(t1=='P')
			{
				if(t2=='R')p1++;
				else if(t2=='S')p2++;
				else{p1++;p2++;}
			}
		}
		if(p1>p2)cout<<"Player 1\n";
		else if(p1==p2) cout<<"TIE\n";
		else cout<<"Player 2\n";
	}
	return 0;
}