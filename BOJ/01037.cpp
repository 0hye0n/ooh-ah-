#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long n, arr[59], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i < n; i++)cin>>arr[i];
	sort(arr, arr + n);
	if(n > 1)ans = arr[0] * arr[n - 1];
	else ans = arr[0] * arr[0];
	cout<<ans;
	return 0;
}