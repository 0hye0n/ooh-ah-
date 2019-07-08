#include<bits/stdc++.h>

using namespace std;
double sum = 0.0, temp = 1.0;
int main(){
	printf("n e\n");
	printf("- -----------\n");
	for(int i = 0; i<10; i++)
	{
		if(i>0)
			temp = temp*i;
		if(i<=1)
		{
			sum += 1;
			printf("%d %.0lf\n", i, sum);
		}
		
		else if(i==2)
		{
			sum += 1/temp;
			printf("%d %.1lf\n", i, sum);
		}
		else
		{
			sum += 1/temp;
			printf("%d %.9lf\n", i, sum);	
		}			
	}
	
    return 0;
}