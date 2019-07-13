#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string a, b;
char op;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>op>>b;
	if(op=='*')
	{
		int size = a.length() + b.length() - 2;
		cout<<"1";
		for(int i = 0; i < size; i++)cout<<"0";
	}
	else
	{
		int asize = a.length() - 1;
		int bsize = b.length() - 1;
		if(asize == bsize)
		{
			cout<<"2";
			for(int i = 0; i < asize; i++)cout<<"0";	
		}
		else
		{
			cout<<"1";
			int pos = max(asize, bsize) - min(asize, bsize);
			int size = max(asize, bsize);
			for(int i = 0; i < size; i++)
			{
				if(i == pos - 1)cout<<"1";
				else cout<<"0";
			}
		}
	}
	return 0;
}