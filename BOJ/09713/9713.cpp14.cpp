#include<bits/stdc++.h>

using namespace std;
int dp[109], t;
int sum = 0;
int main()
{
	for(int i = 1; i<=100; i++)
	 {
	 	if(i%2==1)sum+=i;
	 	dp[i] = sum;
	 }

	 scanf("%d", &t);
	 for(int i = 0; i<t; i++)
	 	{
	 		int temp;scanf(" %d", &temp);
	 		printf("%d\n", dp[temp]);
	 	}
	return 0;
}