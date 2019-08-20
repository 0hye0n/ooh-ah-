#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, l, arr[1009], ans = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l;

	for(int i = 0; i < n; i++)cin>>arr[i];
	sort(arr, arr + n);
	int cur = 0;
	for(int i = 1; i < n; i++)
	{
		if(arr[cur] + l - 1 < arr[i])
		{
			ans++;
			cur = i;
		}
	}
	cout<<ans;
	return 0;
}