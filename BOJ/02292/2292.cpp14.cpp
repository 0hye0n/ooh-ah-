#include <bits/stdc++.h>
using namespace std;
int n, cnt=1, sum=0;
int main() 
{
	scanf(" %d", &n);
	sum=1;
	while(1)
	{
		if(n<=sum)break;
		sum+=cnt*6;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}