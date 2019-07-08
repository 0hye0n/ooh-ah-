#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
int m;
int cup[3] = {1, 0, 0};
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	scanf("%d", &m);
	for(int i = 0; i<m; i++)
	{
		int x, y;scanf(" %d %d", &x, &y);
		swap(&cup[x-1], &cup[y-1]);
	}
	for(int i = 0; i<3; i++)if(cup[i]==1){printf("%d\n", i+1);break;}
	
	return 0;
}