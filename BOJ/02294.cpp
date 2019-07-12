#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, k, arr[109], dp[10009];
bool check[10009];

vector <int> coin;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;

	for(int i = 0; i < n; i++)cin>>arr[i];
	sort(arr, arr + n);
	coin.push_back(arr[0]);
	for(int i = 1; i < n; i++)if(arr[i] != arr[i - 1])coin.push_back(arr[i]);
	check[0] = true;
	
	int size = coin.size();

	for(int i = 1; i <= k; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(i - coin[j] >= 0)
			{
				if(!check[i] && check[i - coin[j]])
				{
					check[i] = true;
					dp[i] = dp[i - coin[j]] + 1;
				}

				else if(check[i] && check[i - coin[j]])
				{
					dp[i] = min(dp[i], dp[i - coin[j]] + 1);
				}		
			}
		}
	}
	if(dp[k]==0)cout<<"-1";
	else cout<<dp[k];

	return 0;
}