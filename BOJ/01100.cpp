#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			char temp;cin>>temp;
			if(i % 2 == 0 && j % 2 == 0 && temp == 'F')cnt++;
			else if(i % 2 == 1 && j % 2 == 1 && temp == 'F')cnt++;
		}
	}	
	cout<<cnt;
	return 0;
}