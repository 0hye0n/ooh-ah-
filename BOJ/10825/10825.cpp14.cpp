#include <bits/stdc++.h>

using namespace std;

typedef struct node *pnode;
typedef struct node
{
	char name[12];
	pnode link;
};

pnode a[101][101][101] = {NULL}; 

int main() {
	
	int n, result;
	pnode temp, pretemp = NULL;
	
	scanf("%d", &n);
	
	for(int i = 0; i<n ; i++)
	{
		char tname[12];int ascore, bscore, cscore; 
		scanf("%s %d %d %d", &tname, &ascore, &bscore, &cscore);
		
		if(a[ascore][bscore][cscore] == NULL){
		a[ascore][bscore][cscore] = (pnode)malloc(sizeof(node));
		strcpy(a[ascore][bscore][cscore]->name, tname);
		a[ascore][bscore][cscore]->link = NULL;
		}
		
		else
		{
			temp = a[ascore][bscore][cscore];
			
			while(temp)
			{	
				result = strcmp(temp->name, tname);
				if(result<=0)
				{
					pretemp = temp;
					temp = temp->link;
				}
				
				else
				{
					break;
				}
						
			}
			
			if((temp == NULL)&&(result<=0))
			{
				pretemp->link = (pnode)malloc(sizeof(node));
				pretemp = pretemp->link;
				strcpy(pretemp->name, tname);
				pretemp->link = NULL;
			}
			
			else if(temp == a[ascore][bscore][cscore])
			{
				a[ascore][bscore][cscore] = (pnode)malloc(sizeof(node));
				strcpy(a[ascore][bscore][cscore]->name, tname);
				a[ascore][bscore][cscore]->link = temp;
				
			}
			
			else
			{
				if(pretemp == a[ascore][bscore][cscore]){
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
		
		memset(tname, 0, 11);
	}
	
	
	for(int i = 100; i>0; i--)
		for(int j = 1; j<101; j++)
			for(int k = 100; k>0; k--)
				if(a[i][j][k] != NULL)
				{
					temp = a[i][j][k];
					while(temp)
					{
						printf("%s\n", temp->name);
						temp = temp->link;
					}
					
				}
	

	return 0;
}