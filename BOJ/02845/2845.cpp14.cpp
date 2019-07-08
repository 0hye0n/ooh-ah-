#include<bits/stdc++.h>

using namespace std;
int l, p;
int temp;
int num[5];

int main(){
	scanf("%d %d", &l, &p);
	temp = l*p;
	
	for(int i = 0; i<5; i++)
		scanf(" %d", &num[i]);
	
	for(int i = 0; i<5; i++)
		printf("%d ", num[i]-temp);
		
	
    return 0;
}