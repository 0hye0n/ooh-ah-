#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long c, k, m, temp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c>>k;
	temp = pow(10, k-1);
	m = pow(10, k);
	temp = temp * 5;
	long long ans = c + temp;
	cout<<(ans / m) * m;
	return 0;
}