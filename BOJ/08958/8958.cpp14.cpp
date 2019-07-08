#include<bits/stdc++.h>
using namespace std;
int n;
char data[100];
int main(void){
    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
    	scanf(" %s", data);
    	int len = strlen(data), cnt = 0, score = 0;
    	for(int i = 0; i<len; i++)
    	{
    		if(data[i]=='O')
    		{
    			cnt++;
    			score +=cnt;
			}
			
			else
				cnt=0;
		}
		printf("%d\n", score);
	}
    return 0;
}