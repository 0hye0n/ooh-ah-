#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n, cnt=0;
int main()
{
	lld num=1;
	scanf("%lld",&n);
	while(n>0)
	{
		if(num>n)num=1;
		n-=num;
		num++;
		cnt++;
	}
	printf("%lld\n", cnt);
	
	return 0;
}