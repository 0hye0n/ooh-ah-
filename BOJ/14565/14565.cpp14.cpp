#include <bits/stdc++.h>

using namespace std;

bool flag = false;
long long n, a, add;

long long uclid(long long x, long long y)
{
	long long a = max(x, y);
	long long b = min(x, y);
	long long R = a % b;

	while(R)
	{
		a = b;
		b = R;
		R = a % b;
	}

	return b;
}

long long extended_uclid(long long x, long long y)
{
	long long s0 = 1, s1 = 0, t0 = 0, t1 = 1, r0 = x, r1 = y, i = 1;
	long long q, temp;
	while(r1 > 0)
	{
		q = r0 / r1;
		temp = s1;
		s1 = s0 - s1 * q;
		s0 = temp;
		
		temp = t1;
		t1 = t0 - t1 * q;
		t0 = temp;
		
		temp = r1;
		r1 = r0 - r1 * q;
		r0 = temp;
		i++;
	}
	return t0;
}

int main()
{
	scanf("%lld %lld", &n, &a);
	cout<<n - a<<" ";
	if(uclid(n, a) != 1)cout<<"-1";
	else
	{
		long long ans = extended_uclid(n, a);
		cout<<(ans > 0 ? ans : n+ans);
	}


	return 0;

}