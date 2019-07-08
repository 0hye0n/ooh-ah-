#include <bits/stdc++.h>

using namespace std;

int main() {

	int dice[3];
	for(int i = 0; i<3; i++)
	scanf("%d", &dice[i]); 
	
	
	if((dice[0]==dice[1])&&(dice[1]==dice[2])&&(dice[2]==dice[0]))
	printf("%d", 10000+dice[0]*1000);
	
	else if((dice[0]==dice[1])||(dice[1]==dice[2])||(dice[2]==dice[0]))
	{
		if(dice[0]==dice[1])
		printf("%d", 1000+dice[0]*100);
		
		else if(dice[1]==dice[2])
		printf("%d", 1000+dice[1]*100);
		
		else if(dice[2]==dice[0])
		printf("%d", 1000+dice[0]*100);
	}
	
	else if((dice[0]!=dice[1])&&(dice[1]!=dice[2])&&(dice[2]!=dice[0]))
	{
		sort(dice, dice+3);
		printf("%d", dice[2]*100);
	}
	return 0;
}