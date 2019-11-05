#include <bits/stdc++.h>

using namespace std;


int n, m, k;
vector<long long> tree, arr;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int s, int e)
{
	if(s == e) return tree[node] = arr[s];

	int mid = (s + e) >> 1;

	return tree[node] = init(arr, tree, node * 2, s, mid) + init(arr, tree, (node * 2) + 1, mid + 1, e);
}

void update(vector<long long> &tree, int node, int s, int e, int idx, long long diff)
{
	if(!(s <= idx && idx <= e)) return;
	
	tree[node] += diff;
	//cout<<diff<<"\n";
	if(s==e)
	{
		return;
	}
	int mid = (s + e) >> 1;
	update(tree, node * 2, s, mid, idx, diff);
	update(tree, (node * 2) + 1, mid + 1, e, idx, diff);
}

long long sum(vector<long long> &tree, int node, int s, int e, int left, int right)
{
	if(e < left || right < s) return 0;
	if(left <= s && e <= right) return tree[node];

	int mid = (s + e) >> 1;

	return sum(tree, node * 2, s, mid, left, right) + sum(tree, (node * 2) + 1, mid + 1, e, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin>>n>>m>>k;

	arr.resize(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree.resize(tree_size);
	
	for(int i = 0; i < n; i++)cin>>arr[i];
	init(arr, tree, 1, 0, n - 1);

	int size = m + k;
	for(int i = 0; i < size; i++)
	{
		int a;cin>>a;
		
		if(a == 1)
		{
			int b;
			long long c;
			cin>>b>>c;
			update(tree, 1, 0, n - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else
		{
			int b, c;cin>>b>>c;
			cout<<sum(tree, 1, 0, n - 1, b - 1, c - 1)<<"\n";
		}
	}

	return 0;
}