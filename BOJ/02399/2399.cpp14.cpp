#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n;
lld x[10009], sum=0;
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf("%lld", &x[i]);
	sort(x, x+n);lld temp=0;
	for(int i = 1; i<n; i++)
	{
		temp += x[i-1];
		sum += x[i]*i-temp;
	}
	
	printf("%lld\n", sum*2);
	
	return 0;
}