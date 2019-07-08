#include <bits/stdc++.h>
 
using namespace std;
int n, sum=0;
char name[109];
int main() {
	scanf("%d", &n);
	scanf("%s", &name);	
	for(int i = 0; i<n; i++)
	{
		sum+=name[i]-64;
	}
	//-64
	
	printf("%d", sum);
	
	return 0;
}