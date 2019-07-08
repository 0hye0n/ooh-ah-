#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, a[3];
	scanf("%d", &n);	
	
	for(int i = 0; i<n; i++)
		scanf("%d", &a[i]);
		
	sort(a, a+n);
	
	if(n==2){
	for(int i = 1; i<=a[0]; i++)
		if((a[0]%i==0)&&(a[1]%i==0))
			printf("%d\n", i);
	}
	
	else if(n==3){
	for(int i = 1; i<=a[0]; i++)
		if((a[0]%i==0)&&(a[1]%i==0)&&(a[2]%i==0))
			printf("%d\n", i);
	}
	return 0;
}