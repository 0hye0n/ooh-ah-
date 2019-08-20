#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 1; i <= n; i++)
	{
		int temp = i, sum = i;

		while(temp)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if(sum == n){cout<<i;return 0;}
	}
	cout<<"0";


	return 0;
}