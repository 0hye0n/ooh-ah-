#include <bits/stdc++.h>

using namespace std;

int value[20001];

int main() {
	
	int n, sum = 0;
	scanf("%d", &n);
	
	for(int i = 0; i<2*n; i++)
		scanf(" %d", &value[i]);
		
	for(int i = 0; i<2*n; i++)
	{
		if(value[i]<0)
			sum += -value[i];
		
		else
			sum += value[i];
	}
	
	printf("%d", sum);
	
		
	return 0;
}


