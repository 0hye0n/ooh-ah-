#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>b;

	if(a.length() < b.length()) cout<<"no";
	else cout<<"go";
	return 0;
}