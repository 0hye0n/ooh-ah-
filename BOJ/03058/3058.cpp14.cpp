#include <bits/stdc++.h>
using namespace std;
int t, data[7];
int main() 
{
	scanf("%d", &t);
	while(t--)
	{
		int sum=0, mn=101;
		for(int i = 0; i<7; i++)scanf("%d", &data[i]);
		sort(data, data+7);
		for(int i = 0; i<7; i++)
		{
			if(data[i]%2==0)
			{
				if(data[i]<mn)mn=data[i];
				sum+=data[i];	
			}
		}
		printf("%d %d\n", sum, mn);
	}
	
	return 0;
}