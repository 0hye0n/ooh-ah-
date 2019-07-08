#include <bits/stdc++.h>

using namespace std;

long long dat[509]; 
double m, rt;
long long temp;
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i<n; i++)
		scanf(" %lld", &dat[i]);
		
	for(int i= k; i<=n; i++)
	{
		double avg = 0, sum = 0;
		for(int j = 0; j<=n-i; j++)
		{
			
			for(int l = j; l<i+j; l++)
			{
				sum += dat[l];
			}
				
			avg = sum/i;
			sum = 0;
			for(int l = j; l<i+j; l++)
			{
				sum += pow(dat[l]-avg, 2);
			}
				
			sum/=i;
			rt = sqrt(sum);
			
			if(i==k&&j==0)
				m = rt;
			
			else if(rt<m)
				m = rt;
			avg=0;sum=0;
		}	
	}
	
	temp=m*100000000000;
	m = temp/100000000000.0;
	
	printf("%.11lf", m);
	
	

	return 0;
}