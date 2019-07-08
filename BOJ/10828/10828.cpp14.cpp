#include <bits/stdc++.h>
 
using namespace std;
int n, top = -1;
int num[10009];

void push(int key)
{
	top++;
	num[top] = key;
}

int pop()
{
	if(top!=-1)
	{
	int nagari = num[top];
	top--;
	return nagari;
	}
	else
		return -1;
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i<n; i++)
	{
		char temp[10];
		scanf(" %s", &temp);
		
		if(strcmp("push", temp)==0)
		{
			int temp1;
			scanf(" %d", &temp1);
			push(temp1);
		}
		
		else if(strcmp("pop", temp)==0)
		{
			printf("%d\n", pop());
		}
		
		else if(strcmp("size", temp)==0)
			printf("%d\n", top+1);
			
		else if(strcmp("empty", temp)==0)
		{
			if(top==-1)
				printf("1\n");
			else
				printf("0\n");
		}	
		
		else if(strcmp("top", temp)==0)
		{
			if(top==-1)
				printf("-1\n");
			else
				printf("%d\n", num[top]);
		}
	}
	return 0;
}