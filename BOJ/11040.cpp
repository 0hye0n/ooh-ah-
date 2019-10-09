#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;

	while(n)
	{
		if(n == 1)
		{
			string in;
			cin>>in;
			cout<<in[in.length() - 1]<<"\n";
			continue;
		}

		stack<int> val;
		stack<char> op;

		for(int i = 0; i < n; i++)
		{
			string in;cin>>in;
			int len = in.length();



		}

		cin>>n;

	}


	return 0;
}