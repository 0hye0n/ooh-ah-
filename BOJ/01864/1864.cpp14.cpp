#include <bits/stdc++.h>

using namespace std;
typedef long long lld;
char data[10];

int main()
{
	int len;
	scanf("%s", data);
	len = strlen(data);
	while(!(len==1&&data[0]=='#'))
	{
		lld temp=1, sum = 0;
		for(int i = len-1; i>=0; i--)
		{
			if(data[i]=='-')sum+=0*temp;
			else if(data[i]=='\\')sum+=1*temp;
			else if(data[i]=='(')sum+=2*temp;
			else if(data[i]=='@')sum+=3*temp;
			else if(data[i]=='?')sum+=4*temp;
			else if(data[i]=='>')sum+=5*temp;
			else if(data[i]=='&')sum+=6*temp;
			else if(data[i]=='%')sum+=7*temp;
			else if(data[i]=='/')sum+=(-1)*temp;
			temp*=8;
		}
		printf("%lld\n", sum);
		scanf("%s", data);
		len = strlen(data);
	}
	return 0;
}