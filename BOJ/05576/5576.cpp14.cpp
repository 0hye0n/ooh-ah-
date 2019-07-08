#include <bits/stdc++.h>
using namespace std;
int data[10];
int main() 
{
	int n = 2;
	while(n--)
	{
		for(int i = 0; i<10; i++)scanf(" %d", &data[i]);
		sort(data, data+10);
		printf("%d ", data[9]+data[8]+data[7]);
	}
	return 0;
}