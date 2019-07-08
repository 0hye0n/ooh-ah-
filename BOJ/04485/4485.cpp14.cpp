#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, d[130][130], res[130][130];
void Dijkstra()
{
	priority_queue <tii, vector<tii>, greater<tii>> pq;
	pq.push(make_tuple(d[0][0], 0, 0));
	bool flag = false;
	while(!pq.empty())
	{
			lld cost = get<0>(pq.top());
			int x = get<1>(pq.top());
			int y = get<2>(pq.top());
			pq.pop();
			if(res[x][y]!=-1)continue;
			res[x][y] = cost;
			for(int i = 0; i<4; i++)
			{
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx<0||ny<0||nx>=n||ny>=n||res[nx][ny]!=-1)continue;
				int tcost = cost + d[nx][ny];
				pq.push(make_tuple(tcost, nx, ny));
			}		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;int i = 1;
	while(n!=0)
	{
		memset(res, -1, sizeof(res));
		for(int i = 0; i<n; i++)
			for(int j = 0; j<n; j++)
				cin>>d[i][j];
		Dijkstra();
		cout<<"Problem "<<i<<": "<<res[n-1][n-1]<<"\n";
		i++;
		cin>>n;
	}
	return 0;
}