#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string ans = "";

void solve(string a)
{
	if(a == "black") ans += "0";
	else if(a == "brown") ans += "1";
	else if(a == "red") ans += "2";
	else if(a == "orange") ans += "3";
	else if(a == "yellow") ans += "4";
	else if(a == "green") ans += "5";
	else if(a == "blue") ans += "6";
	else if(a == "violet") ans += "7";
	else if(a == "grey") ans += "8";
	else if(a == "white") ans += "9";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string in;

	for(int i = 0; i < 2; i++)
	{
		cin>>in;
		solve(in);
	}
	cin>>in;
	long long res = 0;

	for(int i = 0; i < 2; i++)
	{
		res *= 10;
		res += ans[i] - '0';
	}

	if(in == "black"){res *= 1;} 
	else if(in == "brown"){res *= 10;}
	else if(in == "red"){res *= 100;}
	else if(in == "orange"){res *= 1000;}
	else if(in == "yellow"){res *= 10000;}
	else if(in == "green"){res *= 100000;}
	else if(in == "blue"){res *= 1000000;}
	else if(in == "violet"){res *= 10000000;}
	else if(in == "grey"){res *= 100000000;}
	else if(in == "white"){res *= 1000000000;}

	cout<<res;

	return 0;
}