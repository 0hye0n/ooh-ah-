#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int dp[][][], len[509];
string a;


vector<int> make_fail(string target)
{
	int len = target.length();
	vector<int> fail(len, 0);

	for(int i = 1, j = 0; i < len; i++)
	{
		while(j > 0 && target[i] != target[j]) j = fail[j - 1];
		if(target[i] == target[j]) fail[i] = ++j;
	}

	return fail;
}

vector<int> kmp(string a, string b)
{
	int alen = a.length(), blen = b.length();
	vector<int> fail = make_fail(b), ret;

	for(int i = 0, j = 0; i < alen; i++)
	{
		while(j > 0 && a[i] != b[j]) j = fail[j - 1];

		if(a[i] == b[j])
		{
			if(j == blen - 1)
			{
				ret.push_back(i - blen + 1);
				j = fail[j];
			}

			else j++;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	return 0;
}