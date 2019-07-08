#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;


char val[11];

void swap(char *x, char *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(char *a, int n)
{
	int max;
	
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 1; j<n-i; j++){
		if(a[j]>a[j-1]) swap(&a[j-1], &a[j]);
		}
	}
		
}


int main() {

	cin>>val;
	int n = strlen(val);
		
	
	sort(val, n);
	
	
		
	for(int i = 0; i < n; i++){
		cout<<val[i];
	}

	
	
	
	//system("pause");
	return 0;
}