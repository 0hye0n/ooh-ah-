#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, arr[100009];

int solve(int left, int right)
{
	if(left == right) return arr[left];

	int ret = -1, mid = (left + right) / 2;

	int lo = mid, hi = mid + 1, h = min<int>(arr[lo], arr[hi]);

	ret = max<int>({solve(left, mid), solve(mid + 1, right), 2 * h});

	while(lo > left && hi < right)
	{
		if(arr[lo - 1] > arr[hi + 1])
		{
			lo--;
			h = min<int>(arr[lo], h);
			ret = max<int>(ret, h * (hi - lo + 1));
		}

		else
		{
			hi++;
			h = min<int>(arr[hi], h);
			ret = max<int>(ret, h * (hi - lo + 1));
		}
	}

	while(lo > left)
	{
			lo--;
			h = min<int>(arr[lo], h);
			ret = max<int>(ret, h * (hi - lo + 1));
	}

	while(hi < right)
	{
			hi++;
			h = min<int>(arr[hi], h);
			ret = max<int>(ret, h * (hi - lo + 1));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(int i = 0; i < n; i++)cin>>arr[i];

	cout<<solve(0, n - 1);
	return 0;
}