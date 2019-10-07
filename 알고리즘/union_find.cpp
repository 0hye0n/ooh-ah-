#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int parent[1009];

int find(int target)
{
	if(parent[target] < 0) return n;
	parent[target] = find(parent[target]);
	return parent[target];
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b) return;
	parent[a] += parent[b];
	parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	return 0;
}