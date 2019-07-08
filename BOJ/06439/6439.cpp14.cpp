#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c)
{
	int res = a.first*b.second+b.first*c.second+c.first*a.second;
	res -= a.second*b.first+b.second*c.first+c.second*a.first;
	if(res>0)return 1;
	else if(res==0)return 0;
	else return -1;
}
bool intersect(pii a, pii b, pii c, pii d)
{
	int ab = ccw(a, b, c)*ccw(a, b, d);
	int cd = ccw(c, d, a)*ccw(c, d, b);
	if(ab==0 && cd==0)
	{
		if(a>b)swap(a, b);
		if(c>d)swap(c, d);
		return (c<=b&&a<=d);
	}
	return (ab<=0 && cd<=0); 
}
int t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		pii a[6];
		for(int i = 0; i<4; i++)
		{
			int x, y;cin>>x>>y;
			a[i].first = x;
			a[i].second = y;
		}
		if (a[2].first > a[3].first) swap(a[2].first, a[3].first);
		if (a[2].second < a[3].second) swap(a[2].second, a[3].second);
		a[4].first = a[2].first;
		a[4].second = a[3].second;
		a[5].first = a[3].first;
		a[5].second = a[2].second;
		bool check[4] = {false, false, false, false};
		check[0] = intersect(a[0], a[1], a[2], a[3]);
		check[1] = intersect(a[0], a[1], a[4], a[5]);
		check[2] = (a[0].first<=a[3].first&&a[0].first>=a[2].first);
		check[3] = (a[0].second>=a[3].second&&a[0].second<=a[2].second);
		if(check[0]||check[1]||(check[2]&&check[3]))cout<<"T\n";
		else cout<<"F\n";
	}
	return 0;
}