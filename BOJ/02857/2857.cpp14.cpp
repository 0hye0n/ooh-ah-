#include <bits/stdc++.h>
using namespace std;
int RIP[5], pos=0;
int main() {
    for(int i = 0; i<5; i++){char temp[11], *p;
    	scanf("%s", temp);
    	if(strstr(temp, "FBI")){RIP[pos++]=i+1;}}
    if(pos==0){printf("HE GOT AWAY!\n");return 0;}
	for(int i = 0; i<pos; i++)printf("%d ", RIP[i]);
    return 0;}