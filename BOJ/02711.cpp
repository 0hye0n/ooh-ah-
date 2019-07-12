#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;

	while(t--)
	{
		int pos;string temp;
		cin>>pos>>temp;
		int size = temp.length();
		for(int i = 0; i < size; i++)
		{
			if(i == pos - 1)continue;
			cout<<temp[i];
		}
		cout<<"\n";
	}
	return 0;
}