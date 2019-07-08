#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	double x1, y1, r1, x2, y2, r2, distance;
	scanf("%d", &t);
	
	while(t--)
	{
		
		scanf(" %lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		distance = sqrt(pow(x1-x2, 2)+pow(y1-y2, 2));
			
		if(r1==r2&&x1==x2&&y1==y2)
			printf("-1\n");
		else if((r1+r2)<distance||(distance+r1)<r2||(distance+r2)<r1)
			printf("0\n");
		else if((r1+r2)==distance||(distance+r1)==r2||(distance+r2)==r1)
			printf("1\n");
		else if (distance<(r1+r2))
			printf("2\n");
	
	}
	return 0;
}