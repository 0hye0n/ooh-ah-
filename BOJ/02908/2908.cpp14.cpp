#include <bits/stdc++.h>
using namespace std;
char a[4], b[4];
int main() 
{
	int tempa=0, tempb=0;
	scanf("%s %s", a, b);
	for(int i = 0, j=0; i<3; i++,j++)
	{
		tempa += (a[i]-'0')*pow(10, j);
		tempb += (b[i]-'0')*pow(10, j);}
	printf("%d\n", tempa>tempb?tempa:tempb);
	return 0;
}