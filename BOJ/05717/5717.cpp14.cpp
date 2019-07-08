#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() 
{
	while(1)
	{
		scanf("%d %d", &x, &y);
		if(x==0&&y==0)break;
		printf("%d\n", x+y);
	}
	return 0;
}