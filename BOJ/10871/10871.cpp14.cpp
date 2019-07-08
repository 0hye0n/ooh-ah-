#include <bits/stdc++.h>

using namespace std;
 
int a[10001]; 
 
int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		if(a[i]<k)
		printf("%d ", a[i]);
	}
	
	return 0;
}