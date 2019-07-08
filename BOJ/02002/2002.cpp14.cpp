#include <bits/stdc++.h>
 
int n, cnt=0;
char in[10001][10];
int out[10001];

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
		scanf( "%s", &in[i]);
		
	char temp[10];
	
	for(int i = 0; i<n; i++)
	{
		scanf( "%s", &temp);
		for(int j = 0; j<n; j++)
			if(strcmp(temp, in[j])==0) 
			{
				out[i] = j;
				break;
			}
	}

	for(int i = 0; i<n; i++)
	{
		for(int j = i; j<n; j++)
			if(out[i]>out[j])
			{
				cnt++;
				break;
			}
	}
	printf("%d", cnt);
	
		
	
	return 0;
}