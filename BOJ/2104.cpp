#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

long long n, a[100009];

vector<pair<long long, long long>> solve(int left, int right)
{
	vector<pair<long long, long long>> ret(1), l, r;
	ret[0].first = -1;
	ret[0].second = 2e9;

	if(left == right)
	{
		ret[0].first = a[left] * a[left];
		ret[0].second = a[left];

		return ret;
	}

	int mid = (left + right) / 2;

	long long lo = mid, hi = mid + 1, val = a[lo] + a[hi], mn = min(a[lo], a[hi]);

	l = solve(left, mid);
	r = solve(mid + 1, right);

	ret[0].first = max<long long>({l[0].first, r[0].first, val * mn});

	while(lo > left && hi < right)
	{
		if(a[lo - 1] > a[hi + 1])
		{
			lo--;
			val += a[lo];
			mn = min<long long>(mn, a[lo]);
			ret[0].first = max<long long>(ret[0].first, val * mn);
			
		}

		else
		{
			hi++;
			val += a[hi];
			mn = min<long long>(mn, a[hi]);
			ret[0].first = max<long long>(ret[0].first, val * mn);
		}
	}

	while(lo > left)
	{
		lo--;
		val += a[lo];
		mn = min<long long>(mn, a[lo]);
		ret[0].first = max<long long>(ret[0].first, val * mn);
		
	}

	while(hi < right)
	{
		hi++;
		val += a[hi];
		mn = min<long long>(mn, a[hi]);
		ret[0].first = max<long long>(ret[0].first, val * mn);
		
	}
	ret[0].second = mn;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 0; i < n; i++)cin>>a[i];
	vector<pair<long long, long long>> ans = solve(0, n - 1);
	cout<<ans[0].first;
	return 0;
}