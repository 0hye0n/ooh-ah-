#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d",&a);
	for(c=1;c<=a;c++)
	{
		for(d=1;d<=a-c;d++)
        {
			printf(" ");
		}
		for(b=1;b<=2*c-1;b++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}