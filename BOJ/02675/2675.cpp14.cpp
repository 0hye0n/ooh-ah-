#include <bits/stdc++.h>
using namespace std;
int t;
int main() 
{
	scanf("%d", &t);
	while(t--){
		int n;scanf(" %d", &n);
		char data[29];scanf(" %s", data);
		int len = strlen(data);
		for(int i = 0; i<len; i++)
		{
			for(int j = 0; j<n; j++)printf("%c", data[i]);
		}
		printf("\n");
	}

	return 0;
}