#include <stdio.h>
int n, k;
char data[109][109];
int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i<n; i++)scanf("%s", data[i]);
	scanf("%d", &k);
	
	switch(k)
	{
		case 1:
			for(i = 0; i<n; i++)printf("%s\n", data[i]);
			break;
		case 2:
			for(i = 0; i<n; i++)
			{
				for(j = n-1; j>=0; j--)printf("%c", data[i][j]);
				printf("\n");
			}	
			break;
		case 3:
			for(i = n-1; i>=0; i--)printf("%s\n", data[i]);
			break;
	}
   return 0;
}