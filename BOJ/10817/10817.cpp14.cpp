#include <bits/stdc++.h>

using namespace std;
 
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
 
int main() {

	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	
	for(int i = 0; i<3; i++)
		for(int j = 1; j<3-i; j++)
			if(a[j]<a[j-1]) swap(&a[j], &a[j-1]);
			
	printf("%d", a[1]);
	
	
	
	
	
	


	
	return 0;
}