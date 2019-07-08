#include<bits/stdc++.h>
using namespace std;
int t;
char data[5];
int main(){
    scanf("%d", &t);
    for(int i = 0; i<t; i++)
    {
    	scanf("%s", &data);
    	printf("%d\n", data[0]+data[2]-96);
	}
  
    return 0;
}