#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string a;
int n, len[509], dp[100009], mx = 0;
string v[509];
bool check[100009][509];
vector<vector<int>> pos_v;
vector<int> fail;

void make_fail(string target)
{
	fail.clear();
	int len = target.length();
	fail.resize(len);
	for(int i = 1, j = 0; i < len; i++)
	{
		while(j > 0 && target[i] != target[j]) j = fail[j - 1];
		if(target[i] == target[j]) fail[i] = ++j;
	}
}

void kmp(int idx)
{
	int lena = a.length(), lenb = len[idx];
	make_fail(v[idx]);

	for(int i = 0, j = 0; i < lena; i++)
	{
		while(j > 0 && a[i] != v[idx][j]) j = fail[j - 1];

		if(a[i] == v[idx][j])
		{
			if(j == lenb - 1)
			{
				check[i - lenb + 1][idx] = true;
				j = fail[j];
			}

			else ++j;
		}
	}
}

int solve(int pos)
{
	if(pos >= a.length()) return 0;

	int& ret = dp[pos];

	if(ret != -1) return ret;

	ret = solve(pos + 1);

	for(int i = 0; i < n; i++)
	{
		if(check[pos][i])
		ret = max<int>(len[i] + solve(pos + len[i]), ret);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>n;
	pos_v.resize(a.length() + 1);
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
	{
		cin>>v[i];
	}

	for(int i = 0; i < n; i++)
	{
		len[i] = v[i].length();
		kmp(i);
	}

	int alen = a.length();
	cout<<solve(0);
	return 0;
}