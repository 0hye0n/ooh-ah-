#include <bits/stdc++.h>

using namespace std;
int n, data[1000009];
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf("%d", &data[i]);
	sort(data, data+n);
	for(int i = 0; i<n; i++)printf("%d\n", data[i]);
	return 0;
	}