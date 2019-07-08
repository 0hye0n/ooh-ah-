#include <bits/stdc++.h>

using namespace std;


int n;

int res[8];
bool access[9];

void f(int pos)
{
	if(pos==n)
	{
		for(int i= 0; i<n; i++)
			printf("%d ", res[i]);
		
		printf("\n");
		return;
	}
	
	for(int i = 1; i<=n; i++)
	{
		if(!access[i])
		{
			res[pos] = i;
			access[i] = true;
			f(pos+1);
			access[i] = false;
		}
	}
	
}

int main()
{
	scanf("%d", &n);
	
	f(0);
		
	return 0;
}