#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int m, n, mn = 2e9, sum = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>m>>n;

	int start = (int)sqrt(m);
	for(int i = start; i * i <= n; i++)
	{
		int temp = i * i;
		if(temp >= m)
		{
			sum += temp;
			mn = min(temp, mn);	
		} 
	}
	if(sum == 0)cout<<"-1";
	else cout<<sum<<"\n"<<mn;
	return 0;
}