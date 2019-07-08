#include <bits/stdc++.h>
 
using namespace std;
int n;
queue<int> A;
int main() {
	
	scanf("%d", &n);
	for(int i = 0; i<n; i++)
	{
		char temp[10];
		scanf(" %s", temp);
		
		if(strcmp(temp, "push")==0)
		{
			int temp1;
			scanf("%d", &temp1);
			A.push(temp1);
		}
		else if(strcmp(temp, "pop")==0)
		{
			if(A.empty())
				printf("-1\n");
			else
			{printf("%d\n", A.front());
			A.pop();}
		}
		else if(strcmp(temp, "size")==0)
			printf("%d\n", A.size());
		else if(strcmp(temp, "empty")==0)
			printf("%d\n", A.empty());
		else if(strcmp(temp, "front")==0)
		{
			if(A.empty())
				printf("-1\n");
			else
				printf("%d\n", A.front());
		}
			
		else if(strcmp(temp, "back")==0)
		{
			if(A.empty())
				printf("-1\n");
			else
				printf("%d\n", A.back());
		}
			
	}
	
		
	return 0;
}