#include<bits/stdc++.h>

using namespace std;
int check = 0;
char data[109];
char temp[109];
int main(){
	scanf("%s", data);
	int len = strlen(data);
	strcpy(temp, data);
	reverse(temp, temp+len);
	for(int i = 0; i<len; i++)
		if(data[i]!=temp[i]) check++;
		
	if(check>0)
		printf("0");
	else
		printf("1");
    return 0;
}