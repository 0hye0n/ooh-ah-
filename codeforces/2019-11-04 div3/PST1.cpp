#include <bits/stdc++.h>
#define T_SIZE 1000009
//내 스타일로 짠 기본 PST 구현
using namespace std;
vector<int> idx, arr;
int size, n;

struct node{
	node():v(0), left(0), right(0) {}
	int v;
	node *left, *right;
} *tree[T_SIZE];

int get_idx(int n)
{
	return lower_bound(idx.begin(), idx.end(), n) - idx.begin();
}

node *make_tree(node *now, int s, int e, int y, int v)
{
	if(y < s || e < y) return now;
	node *ret = new node();
	if(s == e){
		ret->v = now->v + v;
		return ret;
	}

	int mid = (s + e) >> 1;
	ret->left = make_tree(now->left, s, mid, y, v);
	ret->right = make_tree(now->right, mid + 1, e, y, v);
	ret -> v = (ret->left ? ret->left->v : 0) + (ret->right ? ret->right->v : 0);
	return ret;
}

long long sum(node *now, int s, int e, int left, int right)
{
	if(s < left || right < e) return 0;
	if(left <= s && e <= right) return now->v;

	int mid = (s + e) >> 1;
	return (now->left ? sum(now->left, s, mid, left, right) : 0) + (now->right ? sum(now->right, s, mid, left, right) : 0); 
}

void init(node *now, int s, int e)
{
	if(s==e) return;
	now->left = new node();
	now->right = new node();
	int mid = (s + e) >> 1;
	init(now->left, s, mid);
	init(now->right, mid + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin>>n;
	arr.resize(n);
	idx.resize(n);
	tree[0] = new node();
	init(tree[0], 0, n - 1);

	for(int i = 0; i < n; i++){
		cin>>arr[i];
		idx[i] = arr[i];
	}
	idx.erase(unique(idx.begin(), idx.end()), idx.end());
	
	for(int i = 1; i <= n; i++)
	{
		tree[i] = make_tree(tree[i - 1], 0, n - 1, get_idx(arr[i]), 1);
		cout<<sum(tree[i], 0, n - 1, 0, n - 1)<<"\n";
	}
	


	return 0;
}