#include <bits/stdc++.h>
using namespace std;
stack <int> a;int n, data[100009];char result[200009];bool check=false;
int main() 
{
	scanf("%d", &n);
	for(int i = 0; i<n; i++)scanf(" %d", &data[i]);
	int num=2, pos=1;
	a.push(1);result[0]='+';
	for(int i = 0; i<n; i++)
	{
		while(1)
		{
			if(a.empty()||data[i]!=a.top())
			{
				if(num>n)
				{
					check = true;break;
				}
				a.push(num++);
				result[pos++]='+';
				
			}
			else if(data[i]==a.top()){a.pop();result[pos++]='-';break;}
			else if(num>n){check = true;break;}
		}
		if(check)break;
	}
	if(check)printf("NO");
	else for(int i = 0; i<pos; i++)printf("%c\n", result[i]);
	return 0;
}