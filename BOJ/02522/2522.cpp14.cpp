#include <bits/stdc++.h>
using namespace std;
int n;
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n-i-1; j++)printf(" ");
		for(int j = 0; j<i+1; j++)printf("*");
		printf("\n");
	}
	for(int i = n-2; i>=0; i--)
	{
		for(int j = 0; j<n-i-1; j++)printf(" ");
		for(int j = 0; j<i+1; j++)printf("*");
		printf("\n");
	}
	
	return 0;
}