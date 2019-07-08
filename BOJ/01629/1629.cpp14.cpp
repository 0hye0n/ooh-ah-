#include <bits/stdc++.h>

using namespace std;
long long a, b, c;

long long POW(long long a, long long b)
{
	if(b == 1) return a % c;

	if(b % 2 == 0)
	{
		long long temp = POW(a, b / 2);
		return (temp % c * temp % c) % c;
	}

	else
	{
		long long temp = POW(a, (b - 1) / 2);
		return (temp % c * temp % c * a % c) % c;
	}
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c;
	cout << POW(a, b);
	return 0;
}