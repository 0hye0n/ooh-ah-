#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, cnt=0;
int main() 
{	
	scanf("%d", &n);
	for(int i = 0; i<5; i++)
	{
		int temp;scanf("%d", &temp);
		if(temp==n)cnt++;	
	}
	printf("%d\n", cnt);
		
	return 0;
}