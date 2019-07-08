#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld a, b, c, x, y, cnt=0;
int main() 
{
	scanf("%lld %lld %lld", &a, &b, &c);
	if(b>=c){printf("-1\n");return 0;}
	cnt = a/(c-b)+1;
	printf("%lld", cnt);
	return 0;
}