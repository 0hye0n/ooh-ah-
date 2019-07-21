#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int c;

string solve(string::iterator& it)
{
	char cur = *it;
	++it;
	if(cur == 'w' || cur == 'b')return string(1, cur);

	string upleft = solve(it);
	string upright = solve(it);
	string downleft = solve(it);
	string downright = solve(it);

	return string("x") + downleft + downright + upleft + upright;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>c;
	while(c--)
	{
		string quad;cin>>quad;
		string::iterator it = quad.begin();
		cout<<solve(it)<<"\n";
	}
	return 0;
}