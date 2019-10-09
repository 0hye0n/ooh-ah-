#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

string a, b;
int fail[1000009] = {0};
vector<int> res;

void make_fail(string target)
{
	int len = target.length();

	for(int i = 1, j = 0; i < len; i++)
	{
		while(j > 0 && target[i] != target[j]) j = fail[j - 1];

		if(target[i] == target[j]) fail[i] = ++j;
	}
}

vector <int> kmp(string a, string b)
{
	vector <int> ret;
	int lena = a.length(), lenb = b.length();

	for(int i = 0, j = 0; i < lena; i++)
	{
		while(j > 0 && a[i] != b[j]) j = fail[j - 1];

		if(a[i] == b[j])
		{
			if(j == lenb - 1)
			{
				ret.push_back(i - lenb + 1);
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
	getline(cin, a);
	getline(cin, b);
	make_fail(b);
	res = kmp(a, b);
	cout<<res.size()<<"\n";
	for(auto p : res)
	{
		cout<<p + 1<<" ";
	}
	return 0;
}