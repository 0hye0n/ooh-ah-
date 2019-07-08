#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld mn, mx;
bool check[1000009];
lld cnt=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>mn>>mx;
	for(lld i = 2; i*i<=mx; i++)
	{
		lld temp = i*i, j = (mn%temp==0)?mn/temp:mn/temp+1;
		for(lld k = j;; k++)
		{
			if(temp*k>mx)break;
			check[temp*k-mn]=true;
		}
	}
	
	lld size = mx-mn+1;
	for(lld i = 0; i<size; i++)if(!check[i])cnt++;
	cout<<cnt;
	return 0;
}