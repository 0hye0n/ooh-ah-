#include <bits/stdc++.h>

using namespace std;


int main() {
	
	unsigned long long a, b, n;
	scanf("%lld %lld", &a, &b);
	
	if(a>b)
	n = a-b-1;
	
	else if(a==b)
	n = 0;
	
	else
	n = b-a-1;
	
	printf("%lld\n", n);
	
	if(a>b){
		for(int i = 0; i<n; i++){
			b++;		
			printf("%lld ", b);
		}
	}
	
	else{
		for(int i = 0; i<n; i++){
			a++;
			printf("%lld ", a);
		}
	}
	
	return 0;
}