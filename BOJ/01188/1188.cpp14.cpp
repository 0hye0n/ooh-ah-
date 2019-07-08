#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n, m;
	scanf("%d %d", &n, &m);
			
		
			int temp;
			int a=0;
			
			for(int i = 1; i<m; i++)
				{
					temp = (n*i)%m;
					
					if(temp) a++; 
				}
				
			printf("%d", a);
		

		
		
	return 0;
}


