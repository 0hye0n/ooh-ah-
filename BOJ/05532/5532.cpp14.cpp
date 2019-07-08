#include <bits/stdc++.h>
using namespace std;
int l, a, b, c, d, cnt=0;
int main() 
{
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	while(a>0||b>0)
	{
		a -= c;
		b -= d;
		cnt++;
	}
	printf("%d", l-cnt);
	return 0;
}