#include <bits/stdc++.h>
 
using namespace std;
char num[4];
int main()
{
	
	while(gets(num))
	{
		printf("%d\n", (num[0]+num[2]-96));
		memset(num, 0, sizeof(num));
	}
	
	return 0;
}
