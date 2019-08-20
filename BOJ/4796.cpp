#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int l, p, v, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>l>>p>>v;

	while(l != 0 || p != 0 || v != 0)
	{	
		cnt++;
		cout<<"Case "<<cnt<<": "<<l * (v / p) + min<int>(l, v % p)<<"\n";
		cin>>l>>p>>v;
	}
	return 0;
}