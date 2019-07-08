#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
lld n;
lld data[59];
int main()
{
	scanf("%lld", &n);
	for(int i = 0; i<n; i++)scanf("%lld", &data[i]);
	sort(data, data+n);
	if(data[1]-data[0]==data[2]-data[1])printf("%lld", data[n-1]+data[1]-data[0]);
	else printf("%lld", data[n-1]*(data[1]/data[0]));
	return 0;
}