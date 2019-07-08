#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int l, w, m[59][59];int mx = 0;
vector <pair<int, int>> st;
bool check[59][59];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>l>>w;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < w; j++)
			{char temp;cin>>temp;
			if(temp=='L')
				{m[i][j]=0;st.push_back(make_pair(i, j));}
			else m[i][j]=1;}
	queue <pair<int, int>> bfs;
	for(auto p : st)
	{
		for(int i = 0; i < l; i++)
			for(int j = 0; j < w; j++)
				check[i][j] = false;
		int cnt=0;
		memset(check, 0, sizeof(check));
		bfs.push(make_pair(p.first, p.second));
		while(!bfs.empty())
			{
				int size = bfs.size();
				while(size--)
				{
					int x = bfs.front().first;
					int y = bfs.front().second;
					bfs.pop();

					for(int k = 0; k<4; k++)
					{
						int nx = x+dx[k];
						int ny = y+dy[k];
						if(nx<0||ny<0||nx>=l||ny>=w||m[nx][ny]==1||check[nx][ny])continue;
						check[nx][ny] = true;
						bfs.push(make_pair(nx, ny));
					}
				}
				cnt++;
			}
			if(mx<cnt)mx = cnt;
		}	
		cout<<mx-1;
	return 0;
}