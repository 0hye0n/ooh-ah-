#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, x1, yy, x2, y2;

bool check(int x, int y, int r)
{
	int r2 = r * r;
	int s = (x1 - x) * (x1 - x) + (yy - y) * (yy - y);
	int e = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);

	if(s <= r2 && e <= r2) return false;
	else if (s > r2 && e > r2)return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;

	while(t--)
	{
		int n, cnt = 0;
		cin>>x1>>yy>>x2>>y2>>n;
		for(int i = 0; i < n; i++)
		{
			int x, y, r;cin>>x>>y>>r;
			if(check(x, y, r))cnt++;
		}

		cout<<cnt<<"\n";
	}	
	return 0;
}