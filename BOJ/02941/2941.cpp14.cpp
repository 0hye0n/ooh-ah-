#include <bits/stdc++.h>
using namespace std;
char data[109];int cnt=0;
int main() 
{
	scanf("%s", data);int len = strlen(data);
	int i;
	for(i = 0; i<len-1;i++){
		if(strncmp(data+i, "c=", 2)==0){cnt++;i++;}
		else if(strncmp(data+i, "c-", 2)==0){cnt++;i++;}
		else if(i<len-2&&strncmp(data+i, "dz=", 3)==0){cnt++;i+=2;}
		else if(strncmp(data+i, "d-", 2)==0){cnt++;i++;}
		else if(strncmp(data+i, "lj", 2)==0){cnt++;i++;}
		else if(strncmp(data+i, "nj", 2)==0){cnt++;i++;}
		else if(strncmp(data+i, "s=", 2)==0){cnt++;i++;}
		else if(strncmp(data+i, "z=", 2)==0){cnt++;i++;}
		else cnt++;
	}
	if(i==len-1)cnt++;
	cout<<cnt;
	return 0;
}