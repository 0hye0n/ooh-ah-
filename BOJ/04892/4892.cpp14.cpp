#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i = 1;
	while(1)
	{
		int temp;
		scanf("%d", &temp);
		if(temp==0)break;

		printf("%d. ", i);
		printf(temp%2==0?"even ":"odd ");
		if(temp%2==0)printf("%d\n", temp/2);
		else printf("%d\n", (temp-1)/2);
		i++;
		}
		
	return 0;
}