#include <bits/stdc++.h>

using namespace std;

char data[1000009];
int cnt = 0;

int main()
{
	scanf("%[^\n]", &data);
	
	if(data[0]!=0 && data[1] !=0)
	cnt++;
	
	for(long i = 1; i<=strlen(data); i++)
		if(data[i] == ' ' && data[i+1]!= 0) cnt++;
	
	
	printf("%d", cnt);
		
	return 0;
}