#include <bits/stdc++.h>
using namespace std;
int a, x, y, mx=0;
int main() 
{
	for(int i = 1; i<=9; i++)
		for(int j = 1; j<=9; j++)
		{
			scanf(" %d", &a);
			if(a>mx){mx=a;x=i;y=j;}
		}
		printf("%d\n%d %d", mx, x, y);
	return 0;
}