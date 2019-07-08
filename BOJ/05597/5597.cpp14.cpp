#include <bits/stdc++.h>
using namespace std;
int data[31];
int main() 
{
	for(int i = 0; i<28; i++)
	{
		int temp;scanf(" %d", &temp);
		data[temp]++;
	}
	for(int i = 1; i<=30; i++)
	if(data[i]==0)printf("%d\n", i);
	return 0;
}