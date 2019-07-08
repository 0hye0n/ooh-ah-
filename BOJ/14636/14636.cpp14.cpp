#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld m, n;
lld mx = 0;
lld mn = 1000000009;
vector<pair<lld, lld>> producer;
vector<pair<lld, lld>> consumer;
vector <pair<lld, lld>> resp;
vector <pair<lld, lld>> resc;

void solve(int lp, int rp, int lc, int rc)
{
	if(lp==rp)return;
	int mp = (lp+rp)/2;
	int mc = -1;
	lld res = -1;
	for(int i = lc; i < rc; i++)
	{
		if(resc[i].first<resp[mp].first||resc[i].second < resp[mp].second)continue;
		lld temp = (resc[i].first-resp[mp].first)*(resc[i].second-resp[mp].second);
		if(temp>res){
			res = temp;
			mc = i;
		}
	}
	mx = max(mx, res);
	if(mc==-1){
		mc = lc;
		while(mc<rc&&resc[mc].first<resp[mp].first)mc++;
	}
	solve(lp, mp, lc, mc+1);
	solve(mp+1, rp, mc, rc);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>m>>n;
	producer.resize(m);
	consumer.resize(n);
	for(int i = 0; i<m; i++)cin>>producer[i].first>>producer[i].second;
	for(int i = 0; i<n; i++)cin>>consumer[i].first>>consumer[i].second;
	sort(producer.begin(), producer.end());
	sort(consumer.begin(), consumer.end());
	reverse(consumer.begin(), consumer.end());

	for(int i = 0; i<m; i++)
	{
		if(!resp.empty()&&resp.back().second<=producer[i].second)continue;
		resp.push_back({producer[i].first, producer[i].second});
	}

	for(int i = 0; i<n; i++)
	{
		if(!resc.empty()&&resc.back().second>=consumer[i].second)continue;
		resc.push_back({consumer[i].first, consumer[i].second});
	}
	reverse(resc.begin(), resc.end());
	solve(0, resp.size(), 0, resc.size());
	cout<<mx;

	return 0;
}