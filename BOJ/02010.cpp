#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long n, sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		long long temp;cin>>temp;
		sum += temp;
	}
	sum -= n-1;
	cout<<sum;
	return 0;
}