#include <bits/stdc++.h>

using namespace std;
int main() {
	int x, y, day=0;
	scanf("%d %d", &x, &y);
	for(int i = 1; i<x; i++)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				day += 31;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				day += 30;
				break;
			case 2:
				day += 28;
		}
	}
	
	day += y;day %= 7;
	switch(day)
	{
		case 0:
			printf("SUN");
			break;
		case 1:
			printf("MON");
			break;
		case 2:
			printf("TUE");
			break;
		case 3:
			printf("WED");
			break;
		case 4:
			printf("THU");
			break;
		case 5:
			printf("FRI");
			break;
		case 6:
			printf("SAT");
	 } 
	return 0;
}
