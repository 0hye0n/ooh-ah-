#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef pair<lld, lld> pii;

lld ccw(pii a, pii b, pii c)
{
	lld res = a.first*b.second+b.first*c.second+c.first*a.second;
	res -= a.second*b.first+b.second*c.first+c.second*a.first;
	if(res>0) return 1;
	else if(res==0) return 0;
	else return -1;
}
pii a[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i<3; i++)cin>>a[i].first>>a[i].second;
	cout<<ccw(a[0], a[1], a[2]);
	return 0;
}