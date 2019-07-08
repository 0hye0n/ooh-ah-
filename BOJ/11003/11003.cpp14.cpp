#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, l;
deque <pair<int, int>> dq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>l;
	for(int i = 0; i<n; i++)
	{
		int temp;cin>>temp;
		while(!dq.empty()&&dq.back().first>=temp)dq.pop_back();
		dq.push_back(make_pair(temp, i));
		if(i-dq.front().second>l-1)dq.pop_front();
		cout<<dq.front().first<<" ";
	}
	return 0;
}