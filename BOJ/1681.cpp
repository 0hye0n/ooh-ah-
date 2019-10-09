#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, l, cnt = 0, res[1000009];
bool flag = false;

void solve_one(int size, int pos)
{
	if(pos == size)
	{
		cnt++;
		if(cnt == n)
		{
			for(int i = 0; i < size; i++) cout<<res[i];
			flag = true;
		}
		return;
	}

	for(int i = 1; i < 10; i++)
	{
		if(i == l)continue;
		res[pos] = i;
		solve_one(size, pos + 1);
	}
}

void solve_more(int size, int pos)
{
	if(pos == size)
	{
		cnt++;
		if(cnt == n)
		{
			
			for(int i = 0; i < size; i++) cout<<res[i];
			flag = true;

		}
		return;
	}

	if(pos == 0)
	{
		for(int i = 1; i < 10; i++)
		{
			if(i == l)continue;
			res[pos] = i;
			solve_more(size, pos + 1);
		}
	}

	else
	{
		for(int i = 0; i < 10; i++)
		{
			if(i == l)continue;
			res[pos] = i;
			solve_more(size, pos + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>l;
	solve_one(1, 0);
	if(!flag)
	{
		for(int i = 2;; i++)
		{
			solve_more(i, 0);
			if(flag)break;
		}	
	}


	
	return 0;
}