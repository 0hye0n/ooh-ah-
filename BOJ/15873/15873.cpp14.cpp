#include<bits/stdc++.h>

using namespace std;
char data[5];
int main(){
	scanf("%s", data);
	
	if(data[1]=='0')
	{
		if(data[3]=='0')
			printf("20\n");
		else
			printf("%d\n", 10+data[2]-48);
	}
	else
	{
		if(data[2]=='0')
			printf("%d", 10+data[0]-48);
		else
			printf("%d", data[0]+data[1]-96);
	}
    return 0;
}