#include <bits/stdc++.h>

using namespace std;

int main() {

	int ang[3], angsum = 0;
	for(int i = 0; i<3; i++)
	scanf("%d", &ang[i]);
	angsum = ang[0]+ang[1]+ang[2]; 
	
	if((ang[0]==60)&&(ang[1]==60)&&(ang[2]==60))
	printf("Equilateral");
	else if((angsum==180)&&((ang[0]==ang[1])||(ang[1]==ang[2])||(ang[2]==ang[0])))
	printf("Isosceles");
	else if((angsum==180)&&((ang[0]!=ang[1])&&(ang[1]!=ang[2])&&(ang[2]!=ang[0])))
	printf("Scalene");
	else
	printf("Error");
	return 0;
}