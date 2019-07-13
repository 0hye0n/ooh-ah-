#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
int x, y, w, h;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>x>>y>>w>>h;
	cout<<min({x, w-x, y, h-y});	
	return 0;
}