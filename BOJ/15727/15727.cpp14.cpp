#include <bits/stdc++.h>
 
using namespace std;
int l;

int main()
{
	scanf("%d", &l);
	if((l%5)!=0)
		printf("%d", (l/5)+1);
	
	else if(l%5==0)
		printf("%d", l/5);
	return 0;
	
}