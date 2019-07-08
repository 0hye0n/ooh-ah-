#include <bits/stdc++.h>

using namespace std;

char data[109]; 
int len, res;
stack<int> a;

int main()
{
	scanf("%s", data);
	len = strlen(data);
	
	for(int i = 0; i<len; i++)
	{
		if((data[i]=='+')||(data[i]=='-')||(data[i]=='*')||(data[i]=='/'))
		{
			int x, y;
			x = a.top();
			a.pop();
			y = a.top();
			a.pop();
			if(data[i]=='+')
				res = y+x;
			else if(data[i]=='-')
				res = y-x;
			else if(data[i]=='*')
				res = y*x;
			else if(data[i]=='/')
				res = y/x;
				
				a.push(res);
		}
		else
			a.push(data[i]-48);
	}
	printf("%d", a.top());
	return 0;
}