#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

//PST
//초기 연산을 할 때마다 각 시점에서 자료구조의 상태를 모두 보존하고 있음
//가상으로 N개의 세그먼트 트리를 두는데 공간 복잡도가 NlogN
//update질의가 없는 2차원 범위 쿼리에서 쓰인다.



struct node{
	node(): (0), left(0), right(0) {}
	int v;
	node *left, *right;
} *Tree[MAXN];

node *make_tree(node *now, int s, int e, int y, int v)
{
	if(y < s || e < y) return now;
	node *ret = new node();
	if(s==e)
	{
		ret->v = now->v + v;
		return ret;
	}
	int m = (s + e) >> 1;
	ret->left = make_tree(now->left, s, m, y, v);
	ret->right = make_tree(now->right, m+1, e, y, v);
	ret->v = (ret->left ? ret->left->v : 0) + (ret->right ? ret->right->v : 0);
	return ret;
}

//y[i] = x 좌표가 i인 점의 y 좌표(1이상 n이하)
Tree[i] = make_tree(Tree[i-1], 1, n, y[i], 1)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);


	return 0;
}