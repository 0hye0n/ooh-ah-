#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() 
{
	scanf("%d %d", &a, &b);
	b -= 45;
	if(b<0){a--;b+=60;}
	if(a<0)a=23;
	printf("%d %d", a, b);
	return 0;
}