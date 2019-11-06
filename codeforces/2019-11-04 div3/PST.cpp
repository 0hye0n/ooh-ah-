#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int n, m, g[100009], par[100009][29], visited[100009], h[100009], sz;
vector<vector<int> > vt;
vector<int> idx;


int getidx(int pos)
{
	return lower_bound(idx.begin(), idx.end(), pos) - idx.begin();
}


struct node{
	int v;
	node *l, *r;
	node(int v, node *l, node *r):v(v), l(l), r(r){}
	node *update(int lo, int hi, int pos)
	{
			if(lo <= pos && pos <= hi)
			{
				if(lo==hi) return new node(v + 1, NULL, NULL);
				int mid = (lo + hi) >> 1;
				return new node(v + 1, l->update(lo, mid, pos), r->update(mid + 1, hi, pos));
			}

			return this;
	}
}*seg[100009];

int query(node *x, node *y, node *anc, node *ancp, int l, int r, int k)
{
	if(l == r) return l;
	int cnt = x->l->v + y->l->v - anc->l->v - ancp->l->v;
	int mid = (l + r) >> 1;
	if(cnt >= k)return query(x->l, y->l, anc->l, ancp->l, l, mid, k);
	return query(x->r, y->r, anc->r, ancp->r, mid + 1, r, k - cnt);
}

void init(int here, int p, int dph)
{
	seg[here] = seg[p]->update(1, sz, getidx(g[here]));
	visited[here] = 1;
	h[here] = dph;
	
	int size = vt[here].size();
	for(int i = 0; i < size; i++)
	{
		int p = vt[here][i];

		if(!visited[p])
		{
			par[p][0] = here;
			init(p, here, dph + 1);
		}
	}
}

int lca(int x, int y)
{
	if(h[x] > h[y]) swap(x, y);

	for(int i = 20; i >= 0; i--)
	{
		if((1 << i) <= h[y] - h[x]) y = par[y][i];
	}
	if(x == y)return x;
	for(int i = 20; i >= 0; i--)
	{
		if(par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
//y[i] = x 좌표가 i인 점의 y 좌표(1이상 n이하)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin>>n>>m;

	for(int i = 1; i <= n; i++)
	{
		cin>>g[i];
		idx.push_back(g[i]);
	}

	sort(idx.begin(), idx.end());
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	sz = idx.size();
	vt.resize(n + 1);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin>>x>>y;
		vt[x].push_back(y);
		vt[y].push_back(x);
	}

	seg[0] = new node(0, NULL, NULL);
	seg[0]->l = seg[0]->r = seg[0];
	init(1, 0, 0);

	for(int i = 1; i < 21; i++)
		for(int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];

	for(int i = 0; i < m; i++)
	{
		int x, y, k;cin>>x>>y>>k;
		int anc = lca(x, y);
		cout<<idx[query(seg[x], seg[y], seg[anc], seg[par[anc][0]], 1, sz, k) - 1]<<"\n";
	}

	return 0;
}