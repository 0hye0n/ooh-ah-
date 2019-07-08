#include<bits/stdc++.h>

using namespace std;
int n;
int mx=-1000009, mn=1000009;
int main(){
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if(temp>mx)mx=temp;
		if(temp<mn)mn=temp;
	}
	
	printf("%d %d", mn, mx);
    return 0;
}