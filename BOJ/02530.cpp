#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int h, m, s, t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>m>>s>>t;
	m = m + (s+t) / 60;
	s = (s+t) % 60;
	h = h + m / 60;
	m = m % 60;
	h %= 24;

	cout<<h<<" "<<m<<" "<<s;

	return 0;
}