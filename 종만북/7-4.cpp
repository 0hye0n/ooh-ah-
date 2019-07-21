#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int c;
vector <int> h;

int solve(int left, int right)
{
	if(left == right) return h[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left , mid), solve(mid + 1, right));

	int height = min(h[mid], h[mid + 1]);

	ret = max(ret, height * 2);

	int l = mid, r = mid + 1;

	while(l > left || r < right)
	{
		if(r < right && (l == left || h[l - 1] < h[r + 1]))
		{
			++r;
			height = min(height, h[r]);
		}
		else
		{
			--l;
			height = min(height, h[l]);
		}
		ret = max(ret, height * (r - l + 1));
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c;

	while(c--)
	{
		int n;cin>>n;
		h.resize(n+1);
		for(int i = 0; i < n; i++)cin>>h[i];
		cout<<solve(0, n-1)<<"\n";
		h.clear();
	}


	return 0;
}