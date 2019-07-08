#include <bits/stdc++.h>
using namespace std;
int data[109];
int dp[109];
int main() 
{
	int n;scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
	int sum = 0;
	for(int i = 0; i<n; i++)dp[i] = data[i]*(i+1);
	printf("%d ", dp[0]);
	for(int i = 1; i<n; i++)printf("%d ", dp[i]-dp[i-1]);
	return 0;
}