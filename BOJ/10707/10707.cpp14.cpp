#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld a, b, c, d, p;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b>>c>>d>>p;
	lld x = a*p;
	lld y = p<=c?b:(b+(p-c)*d);
	cout<<(x>y?y:x);	
	return 0;
}