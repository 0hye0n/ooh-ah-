#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef int i32;
typedef long long i64;
typedef float f32;
typedef double f64;
typedef pair<i32, i32> pii32;
typedef pair<i64, i64> pii64;
i64 a1, b1, a2, b2, resa, resb;
i32 main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a1>>b1>>a2>>b2;
	resa = a1 * b2 + a2 * b1;
	resb = b1 * b2;

	if(resa>resb)
	{
		i64 cur = resa, gcd = resb;
		while(cur%gcd!=0)
		{
			i64 temp = cur;
			cur = gcd;
			gcd = temp%gcd;
		}
		resa/=gcd;
		resb/=gcd;
	}
	else
	{
		i64 cur = resb, gcd = resa;
		while(cur%gcd!=0)
		{
			i64 temp = cur;
			cur = gcd;
			gcd = temp%gcd;
		}
		resa/=gcd;
		resb/=gcd;
	}
	cout<<resa<<" "<<resb;

	return 0;
}