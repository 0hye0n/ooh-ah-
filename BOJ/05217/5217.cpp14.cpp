#include <bits/stdc++.h>

using namespace std;
int t, data[109];

int main()
{	
	scanf("%d", &t);
	for(int i = 0; i<t; i++)scanf(" %d", &data[i]);

	for(int i = 0; i<t; i++)
	{
		printf("Pairs for %d: ", data[i]);
		bool access=false;
		for(int j = 1; j<data[i]; j++)
			for(int k = j; k<data[i]; k++)
			{
				if(j+k==data[i]&&j!=k){
					if(!access)
						{
							printf("%d %d", j, k);
							access = true;
						}
					else printf(", %d %d", j, k);
				}
			}
		printf("\n");
		
	}		
	return 0;
}