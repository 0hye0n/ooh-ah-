#include <bits/stdc++.h>

using namespace std;


int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int ret = a.first * b.second + b.first * c.second + c.first * a.second;
	ret -= (a.second * b.first + b.second * c.first + c.second * a.first);

	if(ret < 0) return -1;
	else if(ret > 0) return 1;
	return 0; 
}

bool intersect_ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if(ab == 0 && cd == 0)
	{
		if(a > b)swap(a, b);
		if(c > d)swap(c, d);
		return c <= b && a <= d;
	}

	return ab <= 0 && cd <= 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);


	return 0;
}