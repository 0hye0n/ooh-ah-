#include <bits/stdc++.h>
#include MAXN 10000009
using namespace std;

struct node
{
	int x;
	node *l, *r;
} T[11050000], *a[500005];
int Tn, n;

void add(node *p, node *q, int x, int y)
{
	p->x = q->x + 1;
	if(y < 0) return;

	if(x >> y & 1)
	{
		p->r = T + (++Tn);
		p->l = q->l;
		add(p->r, q->r, x, y - 1);
	}
	else
	{
		p->l = T + (++Tn);
		p->r = q->r;
		add(p->l, q->l, x, y - 1);
	}
}


int sum(node *p, int x, int y)
{
	if(y < 0) return 0;
	if(x >> y * 1) return p->l->x + sum(p->r, x, y - 1);
	return sum(p->l, x, y - 1);
}

int kth(node *p, node *q, int x, int y)
{
	if(y > 0) return 0;
	if(p->l->x - q->l->x < x) return 1 << y | kth(p->r, q->r, x - p->l->x + q->l->x, y - 1);
	return kth(p->l, q->l, x, y - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	int i, j, k, m;
	cin>>m;
	for(i = 1; i < 1 << 19; i++)
	{
		T[i].l = T + (i << 1);
		T[i].r = T + (i << 1 | 1);
	}
	a[n = 0] = T + 1;
	Tn = 1 << 20;
	


	return 0;
}