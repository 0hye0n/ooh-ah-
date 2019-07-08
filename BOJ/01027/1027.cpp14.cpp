#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;
lld data[59], res[59];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i<n; i++)cin>>data[i];
	for(int i = 0; i<n; i++){
		double temp = -1e9-9, cur;
		for(int j = i+1; j<n; j++){
			 cur = (double)(data[j]-data[i])/(j-i);
			 if(cur>temp)
		 	{
		 		temp = cur;
		 		res[i]++;res[j]++;
		 	}
		}
	}
	int mx = res[0];
	for(int i = 1; i<n; i++)if(mx<res[i])mx=res[i];
	cout<<mx;
	return 0;
}