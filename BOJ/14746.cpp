#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, m, c1, c2, P[500009], Q[500009], mn = 2e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>c1>>c2;


	for(int i = 0; i < n; i++)cin>>P[i];
	for(int i = 0; i < m; i++)cin>>Q[i];

	sort(P, P + n);
	sort(Q, Q + m);

	if(n == 1 || m == 1)
	{
		int cnt = 0;

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				int move = (int)abs(P[i] - Q[j]);
				if(mn > move)
				{
					mn = move;
					cnt = 1;
				}

				else if(mn == move)cnt++;
			}

		cout<<(int)abs(c1 - c2) + mn<<" "<<cnt;
		return 0;
	}

	int ppos = 0, qpos = 0, cnt = 1;
	mn = (int)abs(P[ppos] - Q[qpos]);

	while(ppos < n - 1 && qpos < m - 1)
	{	
		int move_p = (int)abs(P[ppos + 1] - Q[qpos]);
		int move_q = (int)abs(P[ppos] - Q[qpos + 1]);

		if(move_p > move_q)
		{
			if(mn > move_q)
			{
				cnt = 1;
				mn = move_q;
			}

			else if(mn == move_q)cnt++;

			qpos++;
		}

		else
		{
			if(mn > move_p)
			{
				cnt = 1;
				mn = move_p;
			}

			else if(mn == move_p)cnt++;

			ppos++;
		}
	}

	if(ppos == n - 1)
		for(int i = ppos; i < n; i++)
			for(int j = qpos + 1; j < m; j++)
			{
				int move = (int)abs(P[i] - Q[j]);
				if(move < mn)
				{
					mn = move;
					cnt = 1;
				}
				else if(move == mn) cnt++;
			}

	else if(qpos == m - 1)
		for(int i = qpos; i < m; i++)
			for(int j = ppos + 1; j < n; j++)
			{
				int move = (int)abs(P[i] - Q[j]);
				if(move < mn)
				{
					mn = move;
					cnt = 1;
				}
				else if(move == mn) cnt++;
			}

	cout<<(int)abs(c1 - c2) + mn<<" "<<cnt;
	return 0;
}