#include <bits/stdc++.h>
 
using namespace std;
char n[100009];
int lnum[100009];
int len, begn=0, sum=0;
char pattern[3] = {'(', ')', '\0'};

int main() {
	scanf("%s", &n);
	len = strlen(n);
	for(int i = 0; i<len; i++)
	{
		if(strncmp(pattern, &n[i], 2)==0)
		{
			if(begn==0)
			{
				i++;
				continue;
			}
			
			else
			{
				for(int j = 1; j<=begn; j++)
				{
					lnum[j]++;
				}
				i++;
			}
			
			
		}
		
		else if(n[i]=='(')
		{
			begn++;
		}
		
		else if(n[i]==')')
		{
			sum+=lnum[begn]+1;
			lnum[begn]=0;
			begn--;
		}
	}
	
	printf("%d\n", sum);
	return 0;
}
