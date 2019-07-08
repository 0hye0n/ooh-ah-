#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char data[5];
double s;
int main()
{
	scanf("%s", data);
	if(data[0]=='A')s=4.0;
	else if(data[0]=='B')s=3.0;
	else if(data[0]=='C')s=2.0;
	else if(data[0]=='D')s=1.0;
	else if(data[0]=='F')s=0.0;

	if(data[1]=='+')s+=0.3;
	else if(data[1]=='-')s-=0.3;
	printf("%.1lf\n", s);
	return 0;
}