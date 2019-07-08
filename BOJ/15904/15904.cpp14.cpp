#include <bits/stdc++.h>
 
using namespace std;

char data[1009];

int main() {
	scanf("%[^\n]", &data);
	int i, j, n = strlen(data);
	for(i = 0; i< n; i++)
		if(data[i] == 'U') break;
	if(i==n)
	{
		printf("I hate UCPC");
		return 0;
	 } 
	
	for(j = i; j<n; j++)
		if(data[j]=='C') break;
		
	if(j==n)
	{
		printf("I hate UCPC");
		return 0;
	} 
	
	for(i = j; i<n; i++)
		if(data[i]=='P') break;
		
	if(i==n)
	{
		printf("I hate UCPC");
		return 0;
	 } 
	for(j = i; j<n; j++)
		if(data[j] =='C') break;

	
	if(j==n) printf("I hate UCPC");
	
	else printf("I love UCPC");
	return 0;
}