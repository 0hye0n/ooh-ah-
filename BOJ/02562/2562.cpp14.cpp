#include <stdio.h>

int num[9];

int main()
{
	int j,i=0,max = -1, index;

	for (j=0;j<9;j++)
	{
		scanf("%d", &num[i]);
		if (num[i] > max)
		{
			max = num[i];
			index = j;
		}
	}
	printf("%d\n", max);
	printf("%d",index+1);
	return 0;
}