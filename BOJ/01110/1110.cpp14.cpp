#include <bits/stdc++.h>

using namespace std;

int fval[2];
int cycle[2];

int main() {
	
	int n, temp;
	scanf("%d", &n);
	fval[0] = n/10;
	fval[1] = n%10;
	
	//printf("%d %d", fval[0], fval[1]);
	
	cycle[0] = fval[0];
	cycle[1] = fval[1];
	int i = 0;
	while(1)
	{
		i++;
		temp = cycle[0]+cycle[1];
		cycle[0] = cycle[1];
		cycle[1] = temp%10;
		if((fval[0]==cycle[0])&&(fval[1]==cycle[1]))
			break;
	}
	
	printf("%d", i);
	
	
	
	return 0;
}


