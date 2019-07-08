#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int x, y, z, k, sum=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y>>z>>k;
	sum = x+y+z+k;
	int minute = sum/60;
	int sec = sum%60;
	cout<<minute<<"\n"<<sec;

	return 0;
}