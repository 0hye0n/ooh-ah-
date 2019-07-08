#include<bits/stdc++.h>

using namespace std;
char num[1009];
int num1;
int sum = 0;
int main(){
	
	while(1)
	{
		scanf("%s", num);
		int len = strlen(num);
		if(len==1&&num[0]=='0')break;
		
		for(int i = 0; i<len; i++)
			sum+=num[i]-48;
			
		if(sum<10)
			printf("%d\n", sum);
			
		else
		{
			num1 = sum;
		a:
			sum = 0;
		while(num1>0)
		{
			sum += num1%10;
			num1 /= 10;
		}
		if(sum<10)
			printf("%d\n", sum);
		else
		{
			num1 = sum;
			goto a;
		}
		
		}
		sum = 0;	
	}
    return 0;
}