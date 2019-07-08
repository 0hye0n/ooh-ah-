#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

int a, b;

int GCD(int x, int y)
{
	int a = x > y ? x : y;
	int b = x > y ? y : x;
	int R = a % b;

	while(R)
	{
		a = b;
		b = R;
		R = a % b;
	} 
	return b;
}

int LCM(int x, int y)
{
	int a = max(x, y);
	int b = min(x, y);

	for(int i = 1;;i++)
	{
		if(a * i % b==0) return a * i;
	}
}
int main()
{
	scanf("%d %d", &a, &b);
	printf("%d\n", GCD(a, b));
	printf("%d", LCM(a, b));
	return 0;
}