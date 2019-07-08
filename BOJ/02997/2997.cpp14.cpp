#include <bits/stdc++.h>
using namespace std;
typedef long long lld;
int a[3];

int main() 
{	
	for(int i = 0; i<3; i++)scanf(" %d", &a[i]);
	sort(a, a+3);
	if(a[1]-a[0]==a[2]-a[1])printf("%d\n", 2*a[2]-a[1]);
	else if(a[1]-a[0]>a[2]-a[1])printf("%d\n", a[0]+(a[1]-a[0])/2);
	else if(a[1]-a[0]<a[2]-a[1])printf("%d\n", a[1]+(a[2]-a[1])/2);
	return 0;
}