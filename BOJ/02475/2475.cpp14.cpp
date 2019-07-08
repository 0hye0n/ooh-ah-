#include <bits/stdc++.h>

using namespace std;

unsigned long long num[5];

int main() {
	unsigned long long sum=0;
	for(int i = 0; i<5; i++)
	scanf("%lld", &num[i]);
	for(int i = 0; i<5; i++)
	{num[i] = pow(num[i], 2);sum+=num[i];}
	printf("%lld", sum%10);
	return 0;
}