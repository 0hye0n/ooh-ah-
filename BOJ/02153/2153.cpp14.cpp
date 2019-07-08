#include <bits/stdc++.h>
using namespace std;
char data[29];
int sum = 0;
bool check = false;
int main() 
{
	scanf("%s", data);int len = strlen(data);
	for(int i = 0; i<len; i++)
		if(data[i]>='a')sum+=data[i]-'a'+1;
		else sum +=data[i]-38;
	
	for(int i = 2; i<sum; i++)if(sum%i==0){check=true;break;}
	if(!check)printf("It is a prime word.\n");
	else printf("It is not a prime word.\n");
	return 0;
}