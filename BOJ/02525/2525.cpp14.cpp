#include <bits/stdc++.h>

using namespace std;
 
int main() {

	int a, b, c;
	scanf("%d %d", &a, &b);
	scanf("%d", &c);
	
	if((b+c)>=60)
	{
		a += (b+c)/60;
		b = (b+c)%60;
	}
	
	else
		b += c;
		
	a = a%24;
	
	printf("%d %d", a, b);
	
	
	
	return 0;
}