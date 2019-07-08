#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int data, ans;
int main() 
{
	while(1)
	{
		scanf(" %d", &data);
		if(!data)break;
		int num=data;
		while(1)
		{
			int sum = 0;
			while(num>0)
			{
				sum+=num%10;
				num/=10;
			}
			if(sum<10){ans=sum;break;}
			num=sum;
		}
		printf("%d\n", ans);
	}
	return 0;
}