#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int x, y;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y;
	while(x != 0 || y != 0)
	{
		cout<<(x>y?"Yes\n":"No\n");
		cin>>x>>y;
	}
	return 0;
}