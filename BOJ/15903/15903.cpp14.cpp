#include <bits/stdc++.h>
 
using namespace std;

unsigned long long n, m;
unsigned long long num[1009];

int main() {
	scanf("%lld %lld", &n, &m);
	for(int i = 0; i<n; i++)
		scanf(" %lld", &num[i]);
		
	unsigned long long temp;
	
	for(int i = 0; i<m; i++)
	{
		sort(num, num+n);
		temp = num[0] + num[1];
		num[0] = temp;
		num[1] = temp;
	}
	
	unsigned long long sum = 0;
	
	for(int i = 0; i<n; i++)
		sum+=num[i];
	printf("%lld", sum);
	
	return 0;
}