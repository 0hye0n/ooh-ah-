#include <bits/stdc++.h>

using namespace std;
int n, data[100009], mx=-1;
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		scanf(" %d", &data[i]);
	sort(data, data+n);
	for(int i = 0; i<n; i++)
		if(data[i]*(n-i)>mx)mx = data[i]*(n-i);
	printf("%d\n", mx);
	return 0;
	}