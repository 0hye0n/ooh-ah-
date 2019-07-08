#include <bits/stdc++.h>
using namespace std;
char data[5][20];
int main() 
{
	for(int i = 0; i<5; i++)gets(data[i]);
	for(int i = 0; i<15; i++)
		for(int j = 0; j<5; j++)
			if(data[j][i])printf("%c", data[j][i]);
	
	return 0;
}