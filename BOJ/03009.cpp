#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int x[3], y[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 3; i++)cin>>x[i]>>y[i];
	sort(x, x + 3);
	sort(y, y + 3);

	if(x[0] != x[1])cout<<x[0]<<" ";
	else cout<<x[2]<<" ";

	if(y[0] != y[1])cout<<y[0];
	else cout<<y[2];
	return 0;
}