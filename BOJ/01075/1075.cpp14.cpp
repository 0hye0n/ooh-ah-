#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, f;
	scanf("%d", &n);
	scanf("%d", &f);
	
	n = n-n%100;
	while(1)
	{
		if((n%f)==0)
			break;	
		n++;
	}
	
	if((n%100)>9)
	printf("%d", n%100);
	
	else
	printf("0%d", n%100);
	

	return 0;
}