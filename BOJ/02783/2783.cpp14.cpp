#include <bits/stdc++.h>
using namespace std;
double x, y;int n;
double result[109];
int main() 
{
	scanf("%lf %lf", &x, &y);
	result[0] = ((double)x/y)*1000;
	scanf(" %d", &n);
	for(int i = 1; i<=n; i++)
	{
		scanf("%lf %lf", &x, &y);
		result[i] = (double)((x/y)*1000);
	}
	sort(result, result+n+1);
	printf("%.2lf", result[0]);
	return 0;
}