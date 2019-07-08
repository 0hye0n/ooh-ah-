#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int t;
int main()
{
	scanf("%d", &t);
	for(int i = 1; i<=t; i++)
	{
		lld a[3];scanf(" %lld %lld %lld", &a[0], &a[1], &a[2]);
		sort(a, a+3);
		if(a[0]+a[1]>a[2])
		{
			if(a[0]==a[1]&&a[1]==a[2]&&a[0]==a[2])printf("Case #%d: equilateral\n", i);
			else if(a[0]==a[1]||a[1]==a[2])printf("Case #%d: isosceles\n", i);
			else printf("Case #%d: scalene\n", i);
		}
		else printf("Case #%d: invalid!\n", i);
	}
	return 0;
}