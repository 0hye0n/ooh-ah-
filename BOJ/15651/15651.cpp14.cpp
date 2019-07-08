#include <bits/stdc++.h>

using namespace std;

int n, m;
int res[8];
void f(int pos)
{
	if(pos==m)
	{
		for(int i= 0; i<m; i++)
			printf("%d ", res[i]);
		
		printf("\n");
		return;
	}
	
	for(int i = 1; i<=n; i++)
	{
			res[pos] = i;
			f(pos+1);
	}
	
}

int main()
{
	scanf("%d %d", &n, &m);
	f(0);
	return 0;
}