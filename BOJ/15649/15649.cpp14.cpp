#include <bits/stdc++.h>

using namespace std;

int n, m;
int res[8];
bool access[9];

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
		if(!access[i])
		{
			res[pos] = i;
			access[i] = true;
			f(pos+1);
			access[i] = false;
		}
	}
	
}

int main() {

	scanf("%d %d", &n, &m);
	f(0);
	
	return 0;
}
