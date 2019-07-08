#include <bits/stdc++.h>
 
using namespace std;
double a, b, c;
int mx, temp;
int main()
{
	scanf("%lf %lf %lf", &a, &b, &c);
	
	mx = a/b*c;
	temp = a*b/c;
	
	if(temp>mx)
		mx = temp;
		
	printf("%d", mx);
	
	return 0;
	
}
