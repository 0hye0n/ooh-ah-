#include <bits/stdc++.h>
using namespace std;
int d[109][109], n;

void floyd()
{
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			for(int k =  0; k<n; k++)
				if(d[j][i]==1&&d[i][k]==1)d[j][k]=1;
}

int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			scanf(" %d", &d[i][j]);
	floyd();
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			printf("%d ", d[i][j]);
		printf("\n");
	}
	return 0;
}