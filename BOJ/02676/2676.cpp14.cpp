#include <bits/stdc++.h>

using namespace std;

int t[50002];
int n[50002];
int m[50002];
int result[50005];

int main() {
	int t;
	
	scanf("%d", &t);
	
	for(int i = 0; i<t; i++)
		scanf(" %d %d", &n[i], &m[i]);
	
	
	result[0] = 1;
	for(int i = 0; i<t; i++)
	{
		result[n[i]] = 1;
		
		int kn, km, sum = 1;
		
		if(n[i]<=1)
		{
		}
		else if(n[i]%2==0)
		{
			kn = n[i]/2;
			for(int j = 0, r = 1; j<kn; j++, r=r+2)
			{
				sum +=r;
			}
			
			result[kn] = sum;
			
			for(int j = 0, r = 1; j<kn-1; j++, r=r+2)
			{
				sum = sum-r;
				result[kn-j-1] = sum;
				result[kn+j+1] = sum;
				
			}
		}
		
		else
		{
			kn = n[i]/2;
			for(int j = 0, r = 2; j<kn; j++, r=r+2)
			{
				sum +=r;
			}
			
			result[kn] = sum;
			result[kn+1] = sum;
			
			for(int j = 0, r = 2; j<kn-1; j++, r=r+2)
			{
				sum = sum-r;
				result[kn-j-1] = sum;
				result[kn+j+2] = sum;
				
			}
		}
	
		printf("%d\n", result[m[i]]);
	}
	
	return 0;
}


