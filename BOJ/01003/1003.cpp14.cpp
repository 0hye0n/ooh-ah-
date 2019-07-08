#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
lld cnt0[50], cnt1[50];
int main() 
{
	
	cnt0[0] = 1;cnt1[0]=0;
	cnt0[1] = 0;cnt1[1]=1;
	for(int i = 2; i<=40; i++)
	{
		cnt0[i] = cnt0[i-1]+cnt0[i-2];
		cnt1[i] = cnt1[i-1]+cnt1[i-2];
	 } 
	 int t;scanf("%d", &t);
	 while(t--)
	 {
	 	int temp;scanf("%d", &temp);
	 	printf("%d %d\n", cnt0[temp], cnt1[temp]);
	 }
	return 0;
	}