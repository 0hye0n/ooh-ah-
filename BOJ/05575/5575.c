#include <stdio.h>
#include <stdlib.h>
int begin[3], end[3];
int main(){
	int n = 3, i;
	while(n--)
	{
		for(i = 0; i<3; i++)scanf(" %d", &begin[i]);
		for(i = 0; i<3; i++)scanf(" %d", &end[i]);
		
		if(begin[2]>end[2]){end[1]--;end[2]+=60;}
		if(begin[1]>end[1]){end[0]--;end[1]+=60;}
		for(i = 0; i<3; i++)printf("%d ", end[i]-begin[i]);
		printf("\n");
		
	}
	return 0;
}