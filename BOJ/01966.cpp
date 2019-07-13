#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int t, arr[109];
queue <pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		bool flag = false;
		int n, m;cin>>n>>m;int mx, cnt = 1;
		for(int i = 0; i < n; i++)
		{
			cin>>arr[i];
			q.push(make_pair(arr[i], i));
		}
		sort(arr, arr + n);
		mx = n - 1;

		while(!q.empty())
		{
			if(q.front().first == arr[mx])
			{
				if(q.front().second == m)
				{	
					flag = true;
				}

				else
				{
					q.pop();
					mx--;
					cnt++;
				}
			}

			else
			{
				int x = q.front().first, y = q.front().second;
				q.pop();
				q.push(make_pair(x, y));
			}

			if(flag)break;
			
		}
		cout<<cnt<<"\n";
		while(!q.empty())q.pop();
	}
	return 0;
}