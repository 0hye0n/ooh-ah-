#include <bits/stdc++.h>

using namespace std;

int sum(int l, int r, int nodenum, int node_l, int node_r)
{
	if(r < node_l || node_r < l) return 0;
	if(l <= node_l && node_r <= r) return arr[nodenum];
	int mid = (node_l + node_r) >> 1;
	return sum(l, r, nodenum * 2, node_l, mid) + sum(l, r, nodenum * 2 + 1, mid + 1, node_r);
}

void update(int i, int val)
{
	i += size;
	arr[i] = val;
	while(i > 1)
	{
		i /= 2;
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}
}

void construct()
{
	for(int i = MAX_ST / 2 - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);

	return 0;
}