#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string input;

vector<int> make_fail(string target)
{
	int len = target.length();
	vector<int> fail(len, 0);
	for(int i = 1, j = 0; i < len; i++)
	{
		while(j > 0 && target[i] != target[j])
		{
			j = fail[j - 1];	
		}
		if(target[i] == target[j]) fail[i] = ++j;
	}
	return fail;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>input;

	while(input[0] != '.')
	{
		int len = input.length();
		vector<int> fail = make_fail(input);
		bool flag = false;

		for(int i = len; i >= 1; i--)
		{
			if(fail[len - 1] == (double)((double)(i - 1) / i) * (double)len)
			{
				flag = true;
				cout<<i<<"\n";
				break;
			}
		}
		if(!flag)cout<<"1\n";
		cin>>input;
	}
	return 0;
}