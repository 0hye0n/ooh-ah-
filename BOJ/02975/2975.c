#include <stdio.h>

int main() {
	while(1)
	{
		int a, b;char status;
		scanf("%d %c %d", &a, &status, &b);
		if(a==0&&status=='W'&&b==0)break;
		
		if(status=='W')
		{
			if(a-b<-200)printf("Not allowed\n");
			else printf("%d\n", a-b);
		}
		else if(status=='D')printf("%d\n", a+b);
		}	
	
   return 0;
}