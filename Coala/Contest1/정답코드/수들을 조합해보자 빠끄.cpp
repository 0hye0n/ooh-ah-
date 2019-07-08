#include <bits/stdc++.h>
//수들을 조합해보자 빠끄
// 1, 2, 4, 8, 16, 32 이 6개의 수들을 개수에 제한없이 조합하여 더해서 n이나오게 만든다. 이때 최소의 개수를 구하여라
//1<=n<=10000
//첫째줄에 입력 n이 주어진다.
//출력으로는 조합할 수 있는 수들의 최소 개수를 출력한다. 
using namespace std;
int n, mn = 2e9, cnt = 0, ans;
int val[6] = {1, 2, 4, 8, 16, 32};
bool flag = false, check[11000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	queue <int> bfs;
	for(int i = 0; i < 6; i++)
	{
		bfs.push(val[i]);
		check[val[i]] = true;	
	} 

	while(!bfs.empty())
	{
		int size = bfs.size();
		cnt++;

		while(size--)
		{
			int x = bfs.front();
			bfs.pop();

			if(x == n)
			{
				flag = true;
				ans = cnt;
				break;
			}

			for(int i = 0; i < 6; i++)
			{
				int nx = x + val[i];

				if(check[nx] || nx > n) continue;

				bfs.push(nx);
				check[nx] = true;
			}
		}
		if(flag)break;
	}
	cout<<ans;
	return 0;
}