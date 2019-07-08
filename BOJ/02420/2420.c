#include <stdio.h>
#include <stdlib.h>
typedef long long lld;
lld n, m;
int main()
{
	scanf("%lld %lld", &n, &m);
	printf("%lld", (n-m)<0?-(n-m):(n-m));
	return 0;
}