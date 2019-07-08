#include <bits/stdc++.h>

using namespace std;

long long fibo[29], n;

int main()
{
	fibo[0] = 0;
	fibo[1] = 1;
	for(int i = 2; i < 21; i++)
	{
		fibo[i] = fibo[i-1] + fibo[i-2]; 
	}
	scanf("%lld", &n);
	printf("%lld\n", fibo[n]);

	return 0;
}