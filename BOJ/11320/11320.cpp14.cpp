#include <bits/stdc++.h>
int n;
int x[109];
int y[109];
int main() {
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf(" %d %d", &x[i], &y[i]);
	
	for(int i = 0; i<n; i++)
		printf("%d\n", (x[i]*x[i])/(y[i]*y[i]));
	
	
	return 0;
}