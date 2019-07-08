#include<bits/stdc++.h>

using namespace std;
int t, n;
int result[100009];
int main(){
	scanf("%d", &t);
	for(int i = 0; i<t; i++)
	{
		scanf("%d", &n);
		int j;
		for(j = 0; n>0; j++)
		{
			result[j] = n%2;
			n/=2;
		}
		for(int k=0; k<j; k++)
			if(result[k]==1) printf("%d ", k);			
		printf("\n");
		 
	}	
    return 0;
}