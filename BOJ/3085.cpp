#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
char m[59][59];

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

int findMAX()
{
	int mx = -1;

	for(int i = 0; i < n; i++)
	{
		int cnt = 1;
		for(int j = 1; j < n; j++)
		{
			if(m[i][j] != m[i][j - 1])
			{
				mx = max(mx, cnt);
				cnt = 1;
			}

			else cnt++;
		}

		mx = max(mx, cnt);
	}

	for(int i = 0; i < n; i++)
	{
		int cnt = 1;
		for(int j = 1; j < n; j++)
		{
			if(m[j][i] != m[j - 1][i])
			{
				mx = max(mx, cnt);
				cnt = 1;
			}

			else cnt++;
		}

		mx = max(mx, cnt);
	}
	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i = 0; i < n; i++)cin>>m[i];
	ans = findMAX();

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1; j++)
		{
			if(m[i][j] == m[i][j + 1])continue;

			swap(&m[i][j], &m[i][j + 1]);
			ans = max(ans, findMAX());
			swap(&m[i][j], &m[i][j + 1]);
		}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1; j++)
		{
			if(m[j][i] == m[j + 1][i])continue;

			swap(&m[j][i], &m[j + 1][i]);
			ans = max(ans, findMAX());
			swap(&m[j][i], &m[j + 1][i]);
		}

	cout<<ans;

	return 0;
}