#include <bits/stdc++.h>

using namespace std;

typedef struct node *pnode;
typedef struct node
{
	char name[51];
	pnode link;
};

pnode a[51] = {NULL}; 

int main() {
	
	int n, result;
	pnode temp, pretemp = NULL;
	
	scanf("%d", &n);
	
	for(int i = 0; i<n ; i++)
	{
		char tname[51]; 
		scanf("%s", &tname);
		int length = strlen(tname);
		
		if(a[length] == NULL){
		a[length] = (pnode)malloc(sizeof(node));
		strcpy(a[length]->name, tname);
		a[length]->link = NULL;
		}
		
		else
		{
			temp = a[length];
			
			while(temp)
			{	
				result = strcmp(temp->name, tname);
				if(result<0)
				{
					pretemp = temp;
					temp = temp->link;
				}
				
				
				else
				{
					break;
				}
						
			}
			
			if (result == 0)
			{	
			}
			
			else if((temp == NULL)&&(result<0))
			{
				pretemp->link = (pnode)malloc(sizeof(node));
				pretemp = pretemp->link;
				strcpy(pretemp->name, tname);
				pretemp->link = NULL;
			}
			
			else if(temp == a[length])
			{
				a[length] = (pnode)malloc(sizeof(node));
				strcpy(a[length]->name, tname);
				a[length]->link = temp;
				
			}
			
			else
			{
				if(pretemp == a[length]){
					pretemp->link = (pnode)malloc(sizeof(node));
					pretemp = pretemp->link;
					strcpy(pretemp->name, tname);
					pretemp->link = temp;
				}
	
				else{
					pretemp->link = (pnode)malloc(sizeof(node));
					pretemp = pretemp->link;
					strcpy(pretemp->name, tname);
					pretemp->link = temp;
				}
			}
		}
		
		memset(tname, 0, 51);
	}
	
	for(int i = 1; i<51; i++)
				if(a[i] != NULL)
				{
					temp = a[i];
					while(temp)
					{
						printf("%s\n", temp->name);
						temp = temp->link;
					}
	
				}
	

	return 0;
}