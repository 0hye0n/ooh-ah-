#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i32 r, c, zr, zc;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>r>>c>>zr>>zc;
	for(i32 i = 0; i<r; i++)
	{
		char temp[59];cin>>temp;
		for(i32 j = 0; j<zr; j++)
		{
			for(i32 k = 0; k<c; k++)
			{
				for(i32 r = 0; r<zc; r++)
				{
					cout<<temp[k];
				}
			}
			cout<<"\n";
		}
	}
	return 0;
}