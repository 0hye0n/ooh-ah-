#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	while(n--)
	{
		int r, e, c;cin>>r>>e>>c;
		int temp = e-c;
		if(r>temp)cout<<"do not advertise\n";
		else if(r==temp)cout<<"does not matter\n";
		else cout<<"advertise\n";
	}
	return 0;
}