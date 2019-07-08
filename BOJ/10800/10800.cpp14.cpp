#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
struct ball{
	int s, c, num;
};
bool cmp1(const ball &a, const ball &b)
{
	if(a.s!=b.s) return a.s<b.s;
	else if(a.c!=a.c) return a.c<b.c;
	else return a.num<b.num;
}
int n;
vector <ball> data;
lld sum[200009];
lld res[200009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i = 1; i<=n; i++)
	{
		int x, y;cin>>x>>y;
		data.push_back({y, x, i});
	}
	sort(data.begin(), data.end(), cmp1);
	lld total=0;
	for(int i = 0; i<n;)
	{
		int j;
		for(j = i; data[i].s==data[j].s&&j<n; j++)res[data[j].num] = total-sum[data[j].c];
		for(j = i; data[i].s==data[j].s&&j<n; j++)sum[data[j].c]+=data[j].s;
		for(j = i; data[i].s==data[j].s&&j<n; j++)total += data[j].s;
		i=j;
	}
	for(int i = 1; i<=n; i++)cout<<res[i]<<"\n";

	return 0;
}