#include<bits/stdc++.h>
using namespace std;
int n, sum=0;
char data[20];
int main(){
    scanf("%s", data);
    int len = strlen(data);
    for(int i = 0; i<len; i++)
    {
    	if(data[i]=='A'||data[i]=='B'||data[i]=='C')
    		sum+=3;
    	else if(data[i]=='D'||data[i]=='E'||data[i]=='F')
    	sum+=4;
    	else if(data[i]=='G'||data[i]=='H'||data[i]=='I')
    	sum+=5;
    	else if(data[i]=='J'||data[i]=='K'||data[i]=='L')
    	sum+=6;
    	else if(data[i]=='M'||data[i]=='N'||data[i]=='O')
    	sum+=7;
    	else if(data[i]=='P'||data[i]=='Q'||data[i]=='R'||data[i]=='S')
    	sum+=8;
    	else if(data[i]=='T'||data[i]=='U'||data[i]=='V')
    	sum+=9;
    	else if(data[i]=='W'||data[i]=='X'||data[i]=='Y'||data[i]=='Z')
    	sum+=10;
	}
printf("%d\n", sum);
    return 0;
}