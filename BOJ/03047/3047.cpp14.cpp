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
	
	int num;
	int val[3];
	char a[3];
	
	for(int i = 0; i < 3; i++)
		cin>>val[i];
		
	
	sort(val, 3);

		
	for(int i = 0; i < 3; i++)
		cin>>a[i];
	
	
		
	for(int i = 0; i < 3; i++){
		if(a[i] == 'A')
			cout<<val[0];
		else if(a[i] == 'B')
			cout<<val[1];
		else if(a[i] == 'C')
			cout<<val[2];
			
		cout<<endl;
	}
	
	
	
	//system("pause");
	return 0;
}