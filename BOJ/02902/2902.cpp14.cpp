#include <bits/stdc++.h>
using namespace std;
char data[109];
char result[109];
int main() 
{
	scanf("%s", data);int len = strlen(data);
	result[0] = data[0];int pos=1;
	for(int i=1; i<len; i++){if(data[i]==45){result[pos]=data[i+1];pos++;}}
	for(int i=0; i<pos; i++)printf("%c", result[i]);
	
	return 0;
}