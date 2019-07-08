#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[10009];
int coin[109];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; i++)
		scanf(" %d", &coin[i]);
		
	sort(coin, coin+n);
	
	dp[0] = 1;
	for(int i = 0; i<n; i++)
		for(int j = 0; coin[i]+j<=k; j++)
			dp[coin[i]+j] += dp[j];
		
	printf("%d", dp[k]);	
	return 0;
}