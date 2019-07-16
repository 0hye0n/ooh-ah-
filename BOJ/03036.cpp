#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, arr[109];

int uclid(int x, int y)
{
	int a = max(x, y);
	int b = min(x, y);

	while(b)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i < n; i++)cin>>arr[i];

	for(int i = 1; i < n; i++)
	{
		int d = uclid(arr[0], arr[i]);
		cout<<arr[0] / d <<"/"<<arr[i] / d<<"\n";
	}

	return 0;
}