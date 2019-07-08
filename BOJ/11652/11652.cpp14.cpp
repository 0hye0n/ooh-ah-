#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld data[1000009], mx;
lld n, cnt=1, maxcnt=0;
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %lld", &data[i]);
	sort(data, data+n);mx = data[0];
	for(int i = 1; i<n; i++)
	{
		if(data[i]==data[i-1])cnt++;
		else if(data[i]!=data[i-1])	cnt=1;
		if(cnt>maxcnt)
		{
			maxcnt=cnt;
			mx = data[i-1];
		}
	}
	printf("%lld", mx);
	return 0;
	}