#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


using namespace std;


void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int *a, int n)
{
	int max;
	
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 1; j<n-i; j++){
		if(a[j]<a[j-1]) swap(&a[j-1], &a[j]);
		}
	}
		
}


int main() {
	
	int num, val[1000], prev = -1;
	
	cin>>num;
	
	for(int i = 0; i < num; i++)
		cin>>val[i];
		
	sort(val, num);
	
		
	for(int i = 0; i < num; i++){
		cout<<val[i]<<endl;
	}
	
	
	
	//system("pause");
	return 0;
}