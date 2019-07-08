#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int n, k, b;lld sum=0;
int data[109];
int main() 
{
	scanf("%d %d %d", &n, &k, &b);
	for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
	for(int i = b-1; i<b+k-1; i++)sum += data[i%n];
	printf("%d\n", sum);
	return 0;
}