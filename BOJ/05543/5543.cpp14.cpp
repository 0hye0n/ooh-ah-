#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int burger[3], beverage[2];
	int lowest;
	
	scanf("%d %d %d %d %d", &burger[0], &burger[1], &burger[2], &beverage[0], &beverage[1]);
	
	
	lowest = burger[0]+beverage[0]-50;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<2; j++)
		{
			if((i==0)&&(j==0)){}
			
			else
			{
				if(lowest>(burger[i]+beverage[j]-50)) 
					lowest = burger[i]+beverage[j]-50;
			}		
		}
	}
	
	printf("%d", lowest);
		
		
	return 0;
}