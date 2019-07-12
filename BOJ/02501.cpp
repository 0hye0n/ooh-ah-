#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector <int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			if(i == n / i)v.push_back(i);
			
			else
			{
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}	
	sort(v.begin(), v.end());
	if(v.size() < k)cout<<"0";
	else cout<<v[k-1];
	return 0;
}