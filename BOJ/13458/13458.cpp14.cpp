#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n, b, c;
lld num[1000009];
lld sum = 0;
int main()
{	
	scanf("%lld", &n);
	for(int i = 0; i<n; i++)scanf(" %lld", &num[i]);
	scanf(" %lld %lld", &b, &c);
	for(int i = 0; i<n; i++)
	{

		if(num[i]>0)
		{sum += 1;
		num[i]-=b;}
		if(num[i]<0)num[i] = 0;
		sum += num[i]/c;
		if(num[i]%c>0)sum++;
	}
	printf("%lld", sum);	
	return 0;
}