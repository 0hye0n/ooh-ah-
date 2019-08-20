#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int n, score[1009], ans = 0;

vector<pair<int, int>> v;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	fill(score, score + 1009, -1);

	v.resize(n + 1);
	for(int i = 0; i < n; i++)cin>>v[i].second>>v[i].first;

	sort(v.begin(), v.end(), greater<pair<int ,int>>());
	
	for(int i = 0; i < n; i++)
	{
		for(int j = v[i].second; j > 0; j--)
		{
			if(score[j] == -1)
			{
				score[j] = v[i].first;
				ans += v[i].first;
				break;
			}
		}
	}

	cout<<ans;

	return 0;
}