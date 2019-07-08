#include <stdio.h>
double sum = 0.0, mx = -1.0;
int n;
int score[1009];
int main() {
	int i;
	scanf("%d", &n);
	for(i = 0; i<n; i++)
	{
		scanf(" %d", &score[i]);
		if(mx<score[i])mx=score[i];
	}
	for(i = 0; i<n; i++)sum += ((double)score[i]/mx)*100.0;
	printf("%.2lf", sum/(double)n);
   return 0;
}