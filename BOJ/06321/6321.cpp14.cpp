#include<bits/stdc++.h>

using namespace std;
int n;
char data[59];
int main(){
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		scanf(" %s", data);
		int len = strlen(data);
		printf("String #%d\n", i+1);
		for(int j = 0; j<len; j++)
		{
			printf("%c", (data[j]-'A'+1)%26+'A');
		}
		printf("\n\n");
		
	}
    return 0;
}