#include <bits/stdc++.h>
using namespace std;
int cnt[10000001];
int main() {
	unsigned long long n, tmp, sum=0;
	scanf("%lld", &n);
	for(int i = 0; i<n; i++){
		scanf(" %lld", &tmp);
		sum = sum+tmp;
		}
		printf("%lld", sum-n*(n-1)/2);
	return 0;
}
