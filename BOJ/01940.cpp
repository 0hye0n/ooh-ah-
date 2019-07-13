#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, arr[15009], ans = 0;
bool check[15009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;

	for(int i = 0; i < n; i++)cin>>arr[i];
	sort(arr, arr + n);
	
	int left = 0, right = n - 1;

	while(left < right)
	{
		int temp = arr[left] + arr[right];

		if(temp < m)
		{
			left++;
		}

		else if(temp == m)
		{
			left++;
			right--;
			ans++;
		}
		
		else
		{
			right--;
		}
	}
	cout<<ans;

		

	return 0;
}