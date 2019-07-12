#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int m, n, mn = 2e9, sum = 0;
bool check[10009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	check[0] = check[1] = true;
	for(int i = 2; i <= 10009; i++)
		for(int j = 2; i * j <= 10009; j++)
			check[i * j] = true;

	cin>>m>>n;

	for(int i = m; i <= n; i++)
		if(!check[i])
		{
			mn = min(mn, i);
			sum += i;
		}
		if(sum)cout<<sum<<"\n"<<mn;
		else cout<<"-1";
	return 0;
}