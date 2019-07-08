#include <bits/stdc++.h>

using namespace std;

bool check[10009];
void b(int x)
{
	int sum = 0;
	
	sum += x%10;
	sum += (x%100-x%10)/10;
	sum += (x%1000-x%100)/100;
	sum += (x%10000-x%1000)/1000;
	sum += (x%100000-x%10000)/10000;
	
	check[x+sum] = true;
		
}

int main()
{
	for(int i = 0; i<=10000; i++)
		b(i);
	
	for(int i = 1; i<=10000; i++)
		if(!check[i]) printf("%d\n", i);
	
	return 0;
}