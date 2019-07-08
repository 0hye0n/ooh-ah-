#include <bits/stdc++.h>

using namespace std;
  
char num[101];

int main() {

	int n, sum = 0;
	
	scanf("%d", &n);
	
	scanf("%s", num);
	
	for(int i = 0; i<n; i++)
			sum += (int)num[i]-48;
			
		printf("%d", sum);
			
	
	return 0;
}