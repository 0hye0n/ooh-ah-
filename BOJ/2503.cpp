#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

struct BB
{
	string num;
	int strike, ball;
};

int n, res[5];
bool check[11];
vector <BB> v;

int solve(int pos)
{
	int ret = 0;

	if(pos == 3)
	{
		int size = v.size();

		for(int i = 0; i < size; i++)
		{
			int s = 0, b = 0;
			for(int j = 0; j < 3; j++)
			{
				if(v[i].num[j] - '0' == res[j])s++;
				else if(check[v[i].num[j] - '0'])b++;
			}

			if(s != v[i].strike || b != v[i].ball)return 0;
		}

		return 1;
	}

	for(int i = 1; i <= 9; i++)
	{
		if(check[i])continue;
		res[pos] = i;
		check[i] = true;
		ret += solve(pos + 1);
		check[i] = false;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	while(n--)
	{
		string num;
		int strike, ball;
		cin>>num>>strike>>ball;

		v.push_back({num, strike, ball});
	}	
	cout<<solve(0);
	return 0;
}