#include <bits/stdc++.h>

using namespace std;

int n, m;
int result[10];
int access[10];
int check = 0;

void f(int pos)
{
	if(pos == m)
	{
		for(int i = 0; i<m-1; i++)
		{
			if(result[i]>result[i+1]) check++;
		}
 		
		 if(!check)
		{
		for(int i = 0; i < m; i++)
			printf("%d ", result[i]);
			
		printf("\n");
		}
		check = 0;
		return;
	}

	for(int i = 1; i<=n; i++)
	{
		if((!access[i]))
		{
				result[pos] = i; 
				f(pos+1);
		}
		
		if(pos==0)
		access[i] = true;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	
	f(0);
		
	return 0;
}