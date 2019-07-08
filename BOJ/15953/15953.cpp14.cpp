#include <bits/stdc++.h>

using namespace std;
int t, result=0;

int main() {
	scanf("%d", &t);
	int tmp1=0, tmp2=0;

	for(int i = 0; i<t; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		if(tmp1==1)
			result += 5000000;
		else if(tmp1>1&&tmp1<=3)result += 3000000;		
		else if(tmp1>3&&tmp1<=6)
			result += 2000000;
		else if(tmp1>6&&tmp1<=10)
			result += 500000;
		else if(tmp1>10&&tmp1<=15)
				result += 300000;
		else if(tmp1>15&&tmp1<=21)
				result += 100000;

		
		if(tmp2==1)
				result += 5120000;
		else if(tmp2>1&&tmp2<=3)
				result += 2560000;	
		else if(tmp2>3&&tmp2<=7)
				result += 1280000;
		else if(tmp2>7&&tmp2<=15)
				result += 640000;
		else if(tmp2>15&&tmp2<=31)
				result += 320000;
			
		printf("%d\n", result);		
		result=0;
	}
	
	
	return 0;
}