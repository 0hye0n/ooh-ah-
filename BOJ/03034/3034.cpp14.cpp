#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, w, h;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>w>>h;
	int sum = 0;
	while(n--)
	{
		int temp;cin>>temp;
		if(w*w+h*h>=temp*temp)cout<<"DA\n";
		else cout<<"NE\n";
	}
	return 0;
}