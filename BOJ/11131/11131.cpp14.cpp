#include <bits/stdc++.h>

using namespace std;

int balance[101][101];
int cnt[101];
int main() {
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		scanf("%d", &cnt[i]);
		
		for(int j = 0; j<cnt[i]; j++)
			scanf("%d", &balance[i][j]);
	}
	
	for(int i = 0; i<n; i++)
	{
		int sum = 0;
		
		for(int j = 0; j<cnt[i]; j++)
			sum += balance[i][j];
		
		if(sum>0)
		printf("Right\n");
		else if(sum==0)
		printf("Equilibrium\n");
		else
		printf("Left\n");
	}
		
	
	
	
	return 0;
}