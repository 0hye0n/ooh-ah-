#include <bits/stdc++.h>
using namespace std;

int result[100009];

int main() {
	int n, i =0;
	scanf("%d", &n);
	while(i<n)
	{
		int x, y;scanf("%d %d", &x, &y);
		if((x==y)||(x==(2+y)))
		{
			if(x==y){
				if(y%2==0) result[i] = 2*y;
				else result[i] = 1+2*(y-1);}
			else if(x==(2+y)){
				if(y%2==0) result[i] = 2+2*y;
				else  result[i] = 3+2*(y-1);}
		}
		else result[i] =-1;
		i++;
	}
	for(int j=0; j<n; j++){
		if(result[j]==-1) printf("No Number\n");
		else printf("%d\n", result[j]);
		}	
	return 0;
}