#include <bits/stdc++.h>

using namespace std;
int n, ind;
long long target[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};//
long long POW[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
long long tot, sum=1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	tot = n;
	if(n <= 9)
	{
		cout<<n;
		return 0;
	}

	tot -= target[0]-1;
	
	for(int i = 1; i < 9; i++)
	{
		sum*=10;
		long long temp = target[i]-sum;
		if((i+1)*temp<tot)
		{
			tot -= (i+1)*temp;
			continue;
		}
		ind = i;
		break;

	}
	long long temp = tot / (ind + 1);
	long long rem = tot % (ind +1);
	long long ans = POW[ind];
	long long ep = POW[ind+1];
	
	ans += temp;
	if(rem==0)
	{
		ans--;
		//cout<<ans<<"\n";
		cout<<ans%10;
		return 0;
	}
	//cout<<ans<<"\n";
	for(int i = 0; i < rem; i++)
	{
		ans%=ep;
		ep/=10;
	}
	cout<<ans/ep;
}