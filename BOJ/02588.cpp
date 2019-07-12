#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int a, b, res;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;
	res = a * b;
	for(int i = 0; i < 3; i++)
	{
		cout<<a * (b % 10)<<"\n";
		b /= 10;
	}
	cout<<res;
	return 0;
}