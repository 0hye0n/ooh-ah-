#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, size;
string in, cur;
bool check[59];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	cin>>cur;
	n--;
	size = cur.length();

	while(n--)
	{
		cin>>in;
		for(int i = 0; i < size; i++)
		{
			if(in[i] != cur[i])
			{
				check[i] = true;
			}
		}
	}

	for(int i = 0; i < size; i++)
	{
		if(check[i])cout<<"?";
		else cout<<cur[i];
	}
	return 0;
}