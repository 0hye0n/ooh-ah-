#include <bits/stdc++.h>
using namespace std;
int cnt[10], a, b, c, result;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	result = a*b*c;
	for(int i = 0; i<10; i++){int num = result;while(num>0){if(num%10==i)cnt[i]++;num/=10;}}
	for(int i = 0; i<10; i++)printf("%d\n", cnt[i]);
	return 0; 
}