#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int uclid(int x, int y)
{
	int a = max(x, y);
	int b = min(x, y);

	while(1)
	{
		int temp = a;
		a = b;
		b = temp % b;
		if(b == 0)return a;
	}
}

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	for(int i = 0; i < t; i++)
	{
		int x, y;cin>>x>>y;
		int d = uclid(x, y);
		cout<<(x / d) * y<<"\n";

	}
	return 0;
}