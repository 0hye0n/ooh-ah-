#include <bits/stdc++.h>

using namespace std;
int n, data[1009];
int main() {
	
	scanf("%d", &n);
    for(int i = 0; i<n; i++) 
		scanf("%d", &data[i]);
		
    sort(data, data+n);
    
    for(int i = n; i>=0; i--) 
		if(data[n-i]>=i) 
			{
        		printf("%d", i);
        		break;
    		}
	return 0;
}