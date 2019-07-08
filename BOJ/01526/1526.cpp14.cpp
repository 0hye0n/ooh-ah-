#include <bits/stdc++.h>
int n, m;
int temp = 0;


int main() {
	scanf("%d", &n);
	
	for(int i = n; i>=4; i--)
	{
		temp = i;
		
		while(temp)
		{
			if((temp%10!=4)&&(temp%10!=7)) break;
			
			temp/=10;
		}

		if(temp==0) {
			printf("%d", i); break;}
		
	}
	
	
	
	
	return 0;
}