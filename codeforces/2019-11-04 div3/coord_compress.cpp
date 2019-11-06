#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000009];
vector <int> idx;
vector <pair<int, int> > qry;


int getidx(int x)
{
	return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin>>n>>m;
	qry.resize(m + 1);
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		idx.push_back(a[i]);
	}

	for(int i = 0; i < m; i++)
	{
		cin>>qry[i].first>>qry[i].second;
		idx.push_back(qry[i].first);
		idx.push_back(qry[i].second);
	}

	sort(idx.begin(), idx.end());

	idx.erase(unique(idx.begin(), idx.end()), idx.end());


	int size = idx.size();
	for(int i = 0; i < size; i++) cout<<idx[i]<<" ";


	return 0;
}