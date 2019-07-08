#include <bits/stdc++.h>

using namespace std;
typedef long long lld;

int n, l;
int h[1009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>l;
	for(int i=0; i<n; i++)cin>>h[i];
	sort(h, h+n);
	
	for(int i=0; i<n; i++)
	{
		if(l>=h[i])l++;
	}
	
	cout<<l;
	return 0;
}