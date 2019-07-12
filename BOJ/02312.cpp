#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, check[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	check[0] = check[1] = true;
	for(long long i = 2; i <= 100009; i++)
		for(long long j = 2; i * j <= 100009; j++)
			check[i * j] = true;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;

		for(int i = 2; n != 1;i++)
		{
			if(check[i])continue;
			int cnt = 0;
			while(n % i == 0)
			{
				cnt++;
				n /= i;
			}

			if(cnt != 0)cout<<i<<" "<<cnt<<"\n";
		}
	}



	return 0;
}