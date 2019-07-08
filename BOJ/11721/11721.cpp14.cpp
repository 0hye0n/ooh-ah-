#include <bits/stdc++.h>

using namespace std;
char data[101];
int main() {
	scanf("%s", &data);
	for(int i = 0; i<strlen(data); i++)
	{
		printf("%c", data[i]);
		if((i+1)%10==0)printf("\n");
		
	}
	return 0;
}
