#include<bits/stdc++.h>

using namespace std;
int k;
int data[15];
int result[15];
bool access[15];
int check = 0;

void f(int pos)
{
	if(pos==6)
	{		
		for(int i = 0; i<6; i++)
			printf("%d ", result[i]);
			
		printf("\n");
			return;
	}
	
	for(int i = 0; i<k; i++)
	{
		if(!access[i]&&(result[pos-1])<data[i])
		{
			result[pos] = data[i];
			access[i] = true;
			f(pos+1);
			access[i] = false;
		}
	}
}

int main(){
	scanf("%d", &k);	
	while(k!=0)
	{
		for(int i = 0; i<k; i++)
			scanf(" %d", &data[i]);
		f(0);
		
		scanf("%d", &k);
		if(k!=0)
			printf("\n");
	}
	
    return 0;
}