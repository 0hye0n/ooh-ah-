#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t;

int num[109];

void init()
{
	num[0] = 1;
	for(int i = 1; i <= 44; i++)
	{
		num[i] = num[i - 1] + i + 1;
	}
}

bool solve(int k, int pos)
{
	
	if(pos == 3)
	{
		if(k == 0)return true;
		else return false;
	}

	bool ret = false;

	for(int i = 0; i < 44; i++)
	{
		if(k - num[i] < 0)break;

		ret = (ret || solve(k - num[i], pos + 1));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cin>>t;

	while(t--)
	{
		int k;cin>>k;

		cout<<(solve(k, 0) ? "1" : "0")<<"\n";

	}
	return 0;
}