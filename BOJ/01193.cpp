#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int x, pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x;
	for(int i = 1;; i++)
	{
		int sum = (i * (i + 1)) / 2;

		if(sum >= x)
		{
			pos = i;
			x -= ((i - 1)* (i)) / 2; 
			break;
		}
	}
	if(pos % 2 ==0)
	{
		cout<< x << "/" << pos - x + 1;
	}
	else
	{
		cout<< pos - x + 1 << "/" << x;
	}
	return 0;
}