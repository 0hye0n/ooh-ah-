#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int n;
int data[500009];
int main()
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
	sort(data, data+n);
	for(int i = 0; i<n; i++)printf("%d ", data[i]);
	return 0;
}