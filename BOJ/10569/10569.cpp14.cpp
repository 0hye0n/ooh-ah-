#include <bits/stdc++.h>

using namespace std;

int v[101];
int e[101];

int main() {
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf("%d %d", &v[i], &e[i]);
		
	for(int i = 0; i<n; i++)
		printf("%d\n", 2-v[i]+e[i]);
		
	return 0;
}