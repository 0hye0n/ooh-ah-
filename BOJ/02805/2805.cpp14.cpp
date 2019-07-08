#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, m;
lld data[1000009];
lld mx = -1;
lld zero=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i = 0; i<n; i++)
	{
		cin>>data[i];
		mx = max(data[i], mx);
	}
	lld left = 1, right = mx, mid=0;
	while(left<=right)
	{
		mid = (left+right)/2;
		lld sum=0;
		for(int i=0; i<n; i++) sum += max(data[i]-mid, zero);
		if(sum>=m){left = mid+1;}
		else if(sum==m){cout<<mid;return 0;} 
		else {right = mid-1;}
	}
	cout<<right;
	return 0;
}