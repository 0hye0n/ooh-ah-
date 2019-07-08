#include <stdio.h>
typedef long long lld;
int n;
lld pabo[100];
int main() {
	int i, j;
	pabo[0] = 0;
	pabo[1] = 1;
	for(i = 2; i<=45; i++){pabo[i] = pabo[i-1]+pabo[i-2];}
	scanf("%d", &n);
	printf("%lld", pabo[n]);
	
   return 0;
}