#include <bits/stdc++.h>
 
using namespace std;
int n, m;
int table[109][19];
int r[109];
int rdata[109];
int hit[109];
int miss[109];
int col = 0, sum = 0;
int mcnt[109];
int main()
{
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i<n; i++)
		for(int j = 0; j<m+1; j++)
		{
			scanf(" %d", &table[i][j]);
			if(j==0) r[i] = table[i][j];
			else if(table[i][j]==-1)miss[i]++;
			else if(table[i][j]==1)hit[i]++;
			rdata[i] = r[i]-hit[i];
		}
		if(r[0]==m||r[n-1]==0)
	{
		printf("NO\n");
		return 0;
	}
	
	for(int i = 1; i<m+1; i++)
	{
		int one=0, zero = 0, minus = 0;
		for(int j = 0; j<n; j++)
		{
			if(table[j][i]==-1) minus++;
			else if(table[j][i]==1)one++;
			else if(table[j][i]==0)zero++;
		}
		if(one==0)
			mcnt[minus]++;		
		if(zero == n)
		{
			printf("NO\n");
			return 0;
		}
	}
	int j = 0;
	for(int i = 1; i<=n; i++)
	{
		while(1)
		{
			if(rdata[j]>0&&mcnt[i]>0)
				{
					rdata[j]--;
					mcnt[i]--;
				}
			else if(rdata[j]==0&&i>j)
				j++;	
					
			if(mcnt[i]==0)
				break;
			else if(mcnt[i]>0&&rdata[j]==0&&i<=j+1)
				{
					
					printf("NO\n");
					return 0;
				}
		}
	}
		printf("YES\n");
		return 0;
}