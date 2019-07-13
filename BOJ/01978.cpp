#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
bool prime[1009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	prime[0] = prime[1] = true;

	for(int i = 2; i <= 1000; i++)
	{
		for(int j = 2; i * j <= 1000; j++)
		{
			prime[i * j] = true;
		}
	}
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		int temp;cin>>temp;
		if(!prime[temp])cnt++;
	}

	cout<<cnt;
	return 0;
}